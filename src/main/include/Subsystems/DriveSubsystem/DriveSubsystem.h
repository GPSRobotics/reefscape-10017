
#pragma once  

#include <frc/motorcontrol/PWMSparkMax.h>
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>  

#include <frc2/command/SubsystemBase.h>  

#include "Constants.h"

#include "subsystems/DriveSubsystem/Constants.h" 

 class DriveSubsystem : public frc2::SubsystemBase { 

 public: DriveSubsystem(); 

 void Periodic() override;

 void ArcadeDrive(double forward, double rotation); 

 void StrafeLeft(); 

 void StrafeRight(); 

 void StopStrafing();

 void Stop(); 

 private:

//Giving motor names
 ctre::phoenix::motorcontrol::can::WPI_VictorSPX rearLeft; 
 ctre::phoenix::motorcontrol::can::WPI_VictorSPX frontLeft; 
 ctre::phoenix::motorcontrol::can::WPI_VictorSPX rearRight; 
 ctre::phoenix::motorcontrol::can::WPI_VictorSPX frontRight; 

 frc::PWMSparkMax sidewaysMotor{DriveConstants::kSidewaysMotorPort}; 

 };