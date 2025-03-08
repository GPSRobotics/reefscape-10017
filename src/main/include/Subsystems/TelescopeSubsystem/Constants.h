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

namespace TelescopeConstants {
    constexpr int kLeftTelescopeMotorPort = 6;
    constexpr int kRightTelescopeMotorPort = 7;
    constexpr units::length::meter_t kStartPosition = 0.0_m;
    constexpr units::length::meter_t kTelescopeMeterMin = kStartPosition;
    constexpr units::length::meter_t kTelescopeMeterMax = 1.5_m;
    constexpr double kDefaultPower = 0.0;
    //This is a temp value and needs to be measured
    constexpr double kTurnsPerMeter = 1.0;
    constexpr units::length::meter_t kDeadzone = 3.0_cm;
    enum TelescopeStates {
        kTelescopeOff,
        kTelescopePowerMode,
        kTelescopePositionMode
    };


}
