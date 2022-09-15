# Copyright (c) Contributors to the Open 3D Engine Project.
# For complete copyright and license terms please see the LICENSE at the root of this distribution.
#
# SPDX-License-Identifier: Apache-2.0 OR MIT

set(FILES
        Source/Camera/CameraSensor.cpp
        Source/Camera/CameraSensor.h
        Source/Camera/ROS2CameraSensorComponent.cpp
        Source/Camera/ROS2CameraSensorComponent.h
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
        Source/RobotControl/ControlConfiguration.cpp
        Source/RobotControl/ControlConfiguration.h
        Source/RobotControl/ControlSubscriptionHandler.h
        Source/RobotControl/ROS2RobotControlComponent.cpp
        Source/RobotControl/ROS2RobotControlComponent.h
        Source/RobotControl/Ackermann/AckermannBus.cpp
        Source/RobotControl/Ackermann/AckermannBus.h
        Source/RobotControl/Ackermann/AckermannCommandStruct.h
        Source/RobotControl/Ackermann/AckermannSubscriptionHandler.cpp
        Source/RobotControl/Ackermann/AckermannSubscriptionHandler.h
        Source/RobotControl/Controllers/AckermannController/AckermannControlComponent.cpp
        Source/RobotControl/Controllers/AckermannController/AckermannControlComponent.h
        Source/RobotControl/Controllers/RigidBodyController/RigidBodyTwistControlComponent.cpp
        Source/RobotControl/Controllers/RigidBodyController/RigidBodyTwistControlComponent.h
        Source/RobotControl/Twist/TwistBus.cpp
        Source/RobotControl/Twist/TwistBus.h
        Source/RobotControl/Twist/TwistSubscriptionHandler.cpp
        Source/RobotControl/Twist/TwistSubscriptionHandler.h
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
        Source/GNSS/ROS2GNSSSensorComponent.cpp
        Source/GNSS/ROS2GNSSSensorComponent.h
        Source/GNSS/GNSSFormatConversions.cpp
        Source/GNSS/GNSSFormatConversions.h
        Source/Imu/ROS2ImuSensorComponent.cpp
        Source/Imu/ROS2ImuSensorComponent.h
        Source/RobotImporter/ROS2RobotImporterSystemComponent.cpp
        Source/RobotImporter/ROS2RobotImporterSystemComponent.h
        Source/RobotImporter/URDF/UrdfParser.cpp
        Source/RobotImporter/URDF/UrdfParser.h
        Source/Converters/URDF/ToFBX/FbxGenerator.cpp
        Source/Converters/URDF/ToFBX/FbxGenerator.h
        Source/Converters/URDF/ToFBX/FbxNode.cpp
        Source/Converters/URDF/ToFBX/FbxNode.h
        Source/Converters/URDF/ToFBX/UniqueIdGenerator.h
        Source/Converters/URDF/ToFBX/UrdfToFbxConverter.cpp
        Source/Converters/URDF/ToFBX/UrdfToFbxConverter.h
        Source/VehicleDynamics/DriveModels/PidConfiguration.cpp
        Source/VehicleDynamics/DriveModels/PidConfiguration.h
        Source/VehicleDynamics/DriveModels/SimplifiedDriveModel.cpp
        Source/VehicleDynamics/DriveModels/SimplifiedDriveModel.h
        Source/VehicleDynamics/AxleConfiguration.cpp
        Source/VehicleDynamics/AxleConfiguration.h
        Source/VehicleDynamics/ChassisConfiguration.cpp
        Source/VehicleDynamics/ChassisConfiguration.h
        Source/VehicleDynamics/DriveModel.cpp
        Source/VehicleDynamics/DriveModel.h
        Source/VehicleDynamics/ManualControlEventHandler.h
        Source/VehicleDynamics/VehicleInputControlBus.h
        Source/VehicleDynamics/VehicleInputsState.h
        Source/VehicleDynamics/Utilities.cpp
        Source/VehicleDynamics/Utilities.h
        Source/VehicleDynamics/VehicleModelComponent.cpp
        Source/VehicleDynamics/VehicleModelComponent.h
        Source/VehicleDynamics/WheelControllerComponent.cpp
        Source/VehicleDynamics/WheelControllerComponent.h
        )
