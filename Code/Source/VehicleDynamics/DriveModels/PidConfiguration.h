/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
#pragma once

#include <AzCore/Serialization/SerializeContext.h>
#include <control_toolbox/pid.hpp>

namespace VehicleDynamics
{
    //! A wrapper for ROS 2 control_toolbox pid controller.
    //! @see <a href="https://github.com/ros-controls/control_toolbox">control_toolbox</a>.
    class PidConfiguration
    {
    public:
        AZ_TYPE_INFO(PidConfiguration, "{814E0D1E-2C33-44A5-868E-C914640E2F7E}");
        static void Reflect(AZ::ReflectContext* context);

        //! Return initialized control_toolbox Pid.
        //! It will be initialized with member values.
        void InitializePid();

        //! Get PID controller.
        //! @param error Value of difference between target and state since last call
        //! @param deltaTimeNanoseconds change in time since last call (nanoseconds)
        //! @returns Value of computed command
        double ComputeCommand(double error, uint64_t deltaTimeNanoseconds);

    private:
        double m_p = 1.0;
        double m_i = 0.0;
        double m_d = 0.0;
        double m_iMax = 10.0;
        double m_iMin = -10.0;
        bool m_antiWindup = false;

        control_toolbox::Pid m_pid;
    };
} // namespace VehicleDynamics
