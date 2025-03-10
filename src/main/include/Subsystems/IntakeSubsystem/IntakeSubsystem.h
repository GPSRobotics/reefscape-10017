#pragma once


using namespace frc2::whateverItIs;
 
 class IntakeSubsystem : public frc2::SubsystemBase {
 
 public: IntakeSubsystem();

 void Forward(double speed);

 void Reverse(double speed);

 void Grab();

 void Drop();


 private:

 frc2::motor1;
 frc2::motor2;
 

 

 };