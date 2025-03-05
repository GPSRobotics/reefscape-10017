#pragma once 

//Includes
#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix6/TalonFX.hpp>
#include <ctre/phoenix6/CANcoder.hpp>
#include <frc2/command/Command.h>
#include <frc2/command/Commands.h>
#include "Constants.h"

using namespace frc;
class TelescopeSubsystem : public frc2::SubsystemBase{
    public: TelescopeSubsystem();

    void Periodic() override;

    void Spin(double speed);

    void Stop();
};
