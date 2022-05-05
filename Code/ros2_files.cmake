# Copyright (c) Contributors to the Open 3D Engine Project.
# For complete copyright and license terms please see the LICENSE at the root of this distribution.
#
# SPDX-License-Identifier: Apache-2.0 OR MIT

set(FILES
    Source/Clock/SimulationClock.cpp
    Source/Clock/SimulationClock.h
    Source/Lidar/LidarRaycaster.cpp
    Source/Lidar/LidarRaycaster.h
    Source/Lidar/LidarTemplate.cpp
    Source/Lidar/LidarTemplate.h
    Source/Lidar/LidarTemplateUtils.cpp
    Source/Lidar/LidarTemplateUtils.h
    Source/Lidar/ROS2LidarSensorComponent.cpp
    Source/Lidar/ROS2LidarSensorComponent.h
    Source/QoS/QoS.cpp
    Source/QoS/QoS.h
    Source/RobotControl/RobotControl.h
    Source/RobotControl/ROS2RobotControlComponent.cpp
    Source/RobotControl/ROS2RobotControlComponent.h
    Source/RobotControl/TwistControl.cpp
    Source/RobotControl/TwistControl.h
    Source/ROS2ModuleInterface.h
    Source/ROS2SystemComponent.cpp
    Source/ROS2SystemComponent.h
    Source/Sensor/PublisherConfiguration.cpp
    Source/Sensor/PublisherConfiguration.h
    Source/Sensor/ROS2SensorComponent.cpp
    Source/Sensor/ROS2SensorComponent.h
    Source/Sensor/SensorConfiguration.cpp
    Source/Sensor/SensorConfiguration.h
    Source/Frame/NamespaceConfiguration.cpp
    Source/Frame/NamespaceConfiguration.h
    Source/Frame/ROS2FrameComponent.cpp
    Source/Frame/ROS2FrameComponent.h
    Source/Frame/ROS2Transform.cpp
    Source/Frame/ROS2Transform.h
    Source/Utilities/ROS2Conversions.cpp
    Source/Utilities/ROS2Conversions.h
    Source/Utilities/ROS2Names.cpp
    Source/Utilities/ROS2Names.h
    Source/URDF/UrdfParser.cpp
    Source/URDF/UrdfParser.h
    Source/Imu/ROS2ImuSensorComponent.cpp
    Source/Imu/ROS2ImuSensorComponent.h
)
