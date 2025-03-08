#include "subsystems/DriveSubsystem/DriveSubsystem.h" 

 
  //Set names to motors
 DriveSubsystem::DriveSubsystem() :
 rearLeft{DriveConstants::kRearLeftMotorPort}, 
 frontLeft{DriveConstants::kFrontLeftMotorPort}, 
 rearRight{DriveConstants::kRearRightMotorPort}, 
 frontRight{DriveConstants::kFrontRightMotorPort},
 sidewaysMotor{DriveConstants::kLeftSidewaysMotorPort}

 { // Initialize motor settings (e.g., inversion) 


//Set left motors to inverted
 rearLeft.SetInverted(true); 
 frontLeft.SetInverted(true);
 //Keep right motors as is
 rearRight.SetInverted(false); 
 frontRight.SetInverted(false); 
 //Keep sideways motor as is
 sidewaysMotor.SetInverted(false);
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
 sidewaysMotor.Set(-1.0);  // Full speed left 
 
 } 


//Strafe right
  void DriveSubsystem::StrafeRight() {
 sidewaysMotor.Set(1.0);  // Full speed right 

}  

//Stop strafing
void DriveSubsystem::StopStrafing() {
    sidewaysMotor.StopMotor(); 
}

//Stop driving motors
 void DriveSubsystem::Stop() {
    rearLeft.Set(0.0);
    frontLeft.Set(0.0);
    rearRight.Set(0.0);
    frontRight.Set(0.0);
} 

 

 