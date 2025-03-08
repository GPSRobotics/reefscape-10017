#include "subsystems/TelescopeSubsystem/TelescopeSubsystem.h"
#include <frc/smartdashboard/SmartDashboard.h>

using namespace TelescopeConstants;

TelescopeSubsystem::TelescopeSubsystem() :
 LeftTelescopeMotor{TelescopeConstants::kLeftTelescopeMotorPort, rev::spark::SparkLowLevel::MotorType::kBrushless}, 
 RightTelescopeMotor{TelescopeConstants::kRightTelescopeMotorPort, rev::spark::SparkLowLevel::MotorType::kBrushless}
 {
    SmartDashboard::PutNumber("Set Telescope", position.value());
    LeftTelescopeMotor.SetInverted(true);
    RightTelescopeMotor.SetInverted(false);

    rev::spark::SparkBaseConfig config{};
    rev::spark::ClosedLoopConfig pidConfig{};
    pidConfig.P(0.1);
    config.Apply(pidConfig);
    LeftTelescopeMotor.Configure(config, rev::spark::SparkBase::ResetMode::kNoResetSafeParameters, rev::spark::SparkBase::PersistMode::kPersistParameters);
    RightTelescopeMotor.Configure(config, rev::spark::SparkBase::ResetMode::kNoResetSafeParameters, rev::spark::SparkBase::PersistMode::kPersistParameters);
 }

 void TelescopeSubsystem::Periodic(){
    //comment out when using a controller, this is only for testing
    SetTelescopePosition(units::length::meter_t{SmartDashboard::GetNumber("Set Telescope", position.value())});

    if(TelescopeState == kTelescopeOff){
        LeftTelescopeMotor.Set(0.0);
        RightTelescopeMotor.Set(0.0);
    } else if(TelescopeState == kTelescopePowerMode){
        LeftTelescopeMotor.Set(TelescopePower);
        RightTelescopeMotor.Set(TelescopePower);
    } else if(TelescopeState == kTelescopePositionMode){
        units::length::meter_t TelescopePosTarget{(position - kStartPosition).value() * kTurnsPerMeter};
        SmartDashboard::PutNumber("Telescope Actual", GetTelescopePosition().value());
        SmartDashboard::PutNumber("Telescope Actual Turns", (RightTelescopeMotor.GetEncoder().GetPosition()+LeftTelescopeMotor.GetEncoder().GetPosition())/2.0);
        SmartDashboard::PutNumber("Telescope Target Turns", TelescopePosTarget.value());
        // Telescope Target Turns should match Telescope Actual Turns when they mechanism has been manually moved to the correct position
        // i.e. pull the telescope to 0.5_m, set "Set Telescope" to 0.5_m and "Telescope Actual Turns" and "Telescope Target Turns" should match
        
        // LeftTelescopeMotor.GetClosedLoopController().SetReference(TelescopePosTarget.value(), rev::spark::SparkBase::ControlType::kPosition);
        // RightTelescopeMotor.GetClosedLoopController().SetReference(TelescopePosTarget.value(), rev::spark::SparkBase::ControlType::kPosition);

    }

 }

void TelescopeSubsystem::SetTelescopeState(int newState){
    TelescopeState = newState;
}

int TelescopeSubsystem::GetTelescopeState(){
    return TelescopeState;
}

void TelescopeSubsystem::SetTelescopePower(int newPower){
    TelescopePower = newPower;
}

int TelescopeSubsystem::GetTelescopePower(){
    return TelescopePower;
}

void TelescopeSubsystem::SetTelescopePosition(units::length::meter_t newPosition){
    position = newPosition;
    if(position < kTelescopeMeterMin) position = kTelescopeMeterMin;
    if(position > kTelescopeMeterMax) position = kTelescopeMeterMax;

}

units::length::meter_t TelescopeSubsystem::GetTelescopePosition(){
    double left = LeftTelescopeMotor.GetEncoder().GetPosition();
    double right = RightTelescopeMotor.GetEncoder().GetPosition();
    left /= kTurnsPerMeter;
    right /= kTurnsPerMeter;
    return units::length::meter_t{(left + right) / 2} + kStartPosition;
}

bool TelescopeSubsystem::TelescopeIsAtTarget(){
    auto Pos = GetTelescopePosition();
    return Pos > position -(kDeadzone / 2.0) && Pos < position + (kDeadzone / 2.0);
}
