#pragma once

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
#include <numbers>
#include <frc/geometry/Pose2d.h>

//Driving constants
namespace DriveConstants {
    //Wheel motors ports
    constexpr int kRearLeftMotorPort = 0;
    constexpr int kFrontLeftMotorPort = 1;
    constexpr int kRearRightMotorPort = 2;
    constexpr int kFrontRightMotorPort = 3;
    constexpr int kLeftSidewaysMotorPort = 4;
    constexpr int kRightSidewaysMotorPort = 5;
    //constexpr units::meter_t kWheelDiameter = 6.0; //Diameter of wheels
    constexpr units::meters_per_second_t kMaxSpeed = 3.0_mps; // Maximum speed of the robot
}



    
