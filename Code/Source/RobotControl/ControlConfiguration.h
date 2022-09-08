/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
#pragma once

#include "QoS/QoS.h"
#include "RobotControl/RobotConfiguration.h"
#include <AzCore/Component/Entity.h>
#include <AzCore/RTTI/RTTI.h>
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/std/string/string.h>

namespace ROS2
{
    //! Configuration for handling of robot control buses.
    //! Used through ROS2RobotControlComponent.
    struct ControlConfiguration
    { // TODO - this is two things - steering type and subscription configuration. Divide
    public:
        AZ_TYPE_INFO(ControlConfiguration, "{3D3E69EE-0F28-46D5-95F1-956550BA97B9}");

        //! Type of control for the robot.
        //! Different types of steering can fit different platforms,
        //! depending on the type their mobile base (four wheels, omniwheels, ..).
        enum Steering
        {
            Twist, //!< @see <a href="https://docs.ros2.org/latest/api/geometry_msgs/msg/Twist.html">Twist</a>.
            Ackermann //!< @see <a href="https://github.com/ros-drivers/ackermann_msgs/blob/ros2/msg/AckermannDrive.msg">AckermannDrive</a>.
        };

        static void Reflect(AZ::ReflectContext* context);

        QoS m_qos;
        AZStd::string m_topic = "cmd_vel";
        Steering m_steering = Steering::Twist;
    };
} // namespace ROS2
