#pragma once

// Units library headers
#include <units/acceleration.h>
#include <units/angle.h>
#include <units/angular_acceleration.h>
#include <units/angular_velocity.h>
#include <units/current.h>
#include <units/length.h>
#include <units/mass.h>
#include <units/moment_of_inertia.h>
#include <units/time.h>
#include <units/velocity.h>
#include <units/voltage.h>

// WPILib headers
#include <frc/geometry/Pose2d.h>
#include <frc/Encoder.h>
#include <frc/controller/ArmFeedforward.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc2/command/ProfiledPIDSubsystem.h>

// Vendor libraries
#include <ctre/phoenix6/Orchestra.hpp>

// Standard library headers
#include <numbers>

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or bool constants. This should not be used for any other purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

//Field port
namespace GlobalConstants {
    // Miscellaneous robot-wide constants
    constexpr int kArbitrary = 0; // Example constant
    constexpr int kStrafeSpeed = 1.0;
}

//Auton constants
namespace AutoConstants {
    // Maximum speed and acceleration for autonomous
    constexpr auto kMaxSpeed = 4.5_mps; // 4.5 meters per second
    constexpr auto kMaxAcceleration = 2_mps_sq; // 2 meters per second squared

    // Maximum angular speed and acceleration
    constexpr auto kAngularSpeed = 180_deg_per_s; // 180 degrees per second
    constexpr auto kMaxAngularAcceleration = 180_deg_per_s_sq; // 180 degrees per second squared

    // PID gains for trajectory following
    constexpr double kPXController = 0.4; // Proportional gain for X (forward/backward)
    constexpr double kPYController = 0.4; // Proportional gain for Y (strafe)
    constexpr double kPThetaController = 0.0; // Proportional gain for rotation

    // Default starting pose for autonomous (position and rotation)
    constexpr frc::Pose2d kDefaultStartingPose{{1.39_m, 4.11_m}, {180_deg}};
}

//User constants
namespace OIConstants {
    // Joystick/controller ports
    constexpr int kDriverControllerPort = 0; // Port for the driver's controller
    constexpr int kCoDriverControllerPort = 1; // Port for the co-driver's controller
}