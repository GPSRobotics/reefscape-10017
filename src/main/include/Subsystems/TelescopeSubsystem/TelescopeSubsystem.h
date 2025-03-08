#pragma once 

//Includes
#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix6/TalonFX.hpp>
#include <ctre/phoenix6/CANcoder.hpp>
#include <frc2/command/Command.h>
#include <frc2/command/Commands.h>
#include "Constants.h"
#include "rev/SparkMax.h"
using namespace frc;
class TelescopeSubsystem : public frc2::SubsystemBase{
    public: TelescopeSubsystem();

    void Periodic() override;

    void SetTelescopeState(int newState);

    int GetTelescopeState();

    void SetTelescopePower(int newPower);

    int GetTelescopePower();

    void SetTelescopePosition(units::length::meter_t newPosition);

    units::length::meter_t GetTelescopePosition();

    bool TelescopeIsAtTarget();

    
    private:
    int TelescopeState = TelescopeConstants::TelescopeStates::kTelescopePositionMode;
    units::length::meter_t position{TelescopeConstants::kStartPosition};
    double TelescopePower = TelescopeConstants::kDefaultPower;

    rev::spark::SparkMax LeftTelescopeMotor;
    rev::spark::SparkMax RightTelescopeMotor;
};
