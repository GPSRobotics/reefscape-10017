#include "subsystems/DriveSubsystem/DriveSubsystem.h" 

 
  //Set names to motors
 DriveSubsystem::DriveSubsystem() :
 rearLeft{DriveConstants::kRearLeftMotorPort}, 
 frontLeft{DriveConstants::kFrontLeftMotorPort}, 
 rearRight{DriveConstants::kRearRightMotorPort}, 
 frontRight{DriveConstants::kFrontRightMotorPort} 
 { // Initialize motor settings (e.g., inversion) 

//  m_frontLeftMotor.SetInverted(false); 
//  m_rearLeftMotor.SetInverted(false); 
//  m_frontRightMotor.SetInverted(true); 
//  m_rearRightMotor.SetInverted(true); 
//  m_leftSidewaysMotor.SetInverted(false); 
//  m_rightSidewaysMotor.SetInverted(false); 

//Set left motors to inverted
 rearLeft.SetInverted(true); 
 frontLeft.SetInverted(true); 
 rearRight.SetInverted(false); 
 frontRight.SetInverted(false); 
 }  

 void DriveSubsystem::Periodic() {

 }

//Set driving type to arcade
 void DriveSubsystem::ArcadeDrive(double forward, double rotation) {  
 double leftSpeed = forward + rotation; 
 double rightSpeed = forward - rotation; 
 rearLeft.Set(leftSpeed); 
 frontLeft.Set(leftSpeed); 
 rearRight.Set(rightSpeed); 
 frontRight.Set(rightSpeed); 
 }  

//Strafe left 
 void DriveSubsystem::StrafeLeft() {
 m_leftSidewaysMotor.Set(-1.0);  // Full speed left 
 m_rightSidewaysMotor.Set(-1.0); 
 } 


//Strafe right
  void DriveSubsystem::StrafeRight() {
 m_leftSidewaysMotor.Set(1.0);  // Full speed right 
 m_rightSidewaysMotor.Set(1.0); 
}  

//Stop strafing
void DriveSubsystem::StopStrafing() {
    m_leftSidewaysMotor.Set(0.0); 
    m_rightSidewaysMotor.Set(0.0);
}

//Stop driving motors
 void DriveSubsystem::Stop() {
    rearLeft.Set(0.0);
    frontLeft.Set(0.0);
    rearRight.Set(0.0);
    frontRight.Set(0.0);
//  m_frontLeftMotor.StopMotor(); 
//  m_rearLeftMotor.StopMotor(); 
//  m_frontRightMotor.StopMotor(); 
//  m_rearRightMotor.StopMotor(); 
 m_leftSidewaysMotor.StopMotor(); 
 m_rightSidewaysMotor.StopMotor(); } 

 

 