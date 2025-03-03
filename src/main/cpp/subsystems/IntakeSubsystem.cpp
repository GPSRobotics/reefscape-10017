#pragma once



IntakeSubsystem::IntakeSubsystem() : 
 motor1{},
 motor2{}
 {

    
 }

 void IntakeSubsystem::Forward(double speed) {
 double m1speed = speed * value1;
 double m2speed = speed * value2;
 motor1.Set(m1speed);
 motor2.Set(m2speed);
 }

 void IntakeSubsystem::Reverse(double speed) {
 double m1speed = speed * value1 * -1;
 double m2speed = speed * value2 * -1;
 motor1.Set(m1speed);
 motor2.Set(m2speed);
 }

 void IntakeSubsystem::Grab() {
 if Get_X_Pressed {
  motor1.Set(speed);
 } else {
  motor1.Set(0.0);
 }
 }

 void IntakeSubsystem::Drop() {
 if Get_Y_Pressed {
  motor1.Set(speed)
 } else {
  motor1.Set(0.0)
 }
 }