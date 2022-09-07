/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
#pragma once

// Abstracted from ROS message: http://docs.ros.org/en/api/ackermann_msgs/html/msg/AckermannDrive.html
struct AckermannCommandStruct
{
    float m_steeringAngle = 0; // radians
    float m_steeringAngleVelocity = 0; // radians/s
    float m_speed = 0; // m/s
    float m_acceleration = 0; // m/s^2
    float m_jerk = 0; // m/s^3
};