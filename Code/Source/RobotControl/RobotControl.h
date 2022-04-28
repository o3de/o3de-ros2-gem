/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
#pragma once
#include <memory>
#include <rclcpp/rclcpp.hpp>

#include "ROS2/ROS2Bus.h"
#include "Utilities/ROS2Names.h"
#include "RobotControl/ControlConfiguration.h"
#include "RobotControl/RobotConfiguration.h"
#include "Frame/ROS2FrameComponent.h"

namespace ROS2
{
    // Component extension enabling polymorphic use of generics
    // TODO - naming (this is a component activation interface capturing component and entity state)
    class IRobotControl
    {
    public:
        virtual void Activate(const AZ::Entity* entity, const ControlConfiguration& controlConfiguration) = 0;
        virtual void Deactivate() = 0;
        virtual ~IRobotControl() = default;
    };

    template <typename T>
    class RobotControl : public IRobotControl
    {
    public:
        void Activate(const AZ::Entity* entity,
                      const ControlConfiguration& controlConfiguration) final
        {
            m_controlConfiguration = controlConfiguration;
            m_active = true;
            if (!m_controlSubscription)
            {
                auto ros2Frame = entity->FindComponent<ROS2FrameComponent>();
                auto namespacedTopic = ROS2Names::GetNamespacedName(
                        ros2Frame->GetNamespace(),
                        m_controlConfiguration.GetTopic());

                auto ros2Node = ROS2Interface::Get()->GetNode();
                m_controlSubscription = ros2Node->create_subscription<T>(
                    namespacedTopic.data(),
                    m_controlConfiguration.GetControlTopicQoS().GetQoS(),
                    std::bind(&RobotControl<T>::OnControlMessage, this, std::placeholders::_1));
            }
        };

        void Deactivate() final
        {
            m_active = false;
            m_controlSubscription.reset(); // Note: topic and qos can change, need to re-subscribe
        };

    protected:
        ControlConfiguration m_controlConfiguration;

    private:
        void OnControlMessage(const T& message)
        {
            if (!m_active) return;

            if (m_controlConfiguration.IsBroadcastBusMode()) {
                BroadcastBus(message);
            } else {
                ApplyControl(message);
            }
        };

        virtual void ApplyControl(const T& message) = 0;
        virtual void BroadcastBus(const T& message) = 0;

        bool m_active = false;

        typename rclcpp::Subscription<T>::SharedPtr m_controlSubscription;
    };
}  // namespace ROS2