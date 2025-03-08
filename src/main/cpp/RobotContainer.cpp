// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/Autos.h"


RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  //Get joystick position
  drive.SetDefaultCommand(frc2::cmd::Run([this]() {
    double y = controller.GetLeftY();
    double x = -controller.GetRightX();
    
    // Stick drift my beloved
    if(fabs(x) < 0.1) x = 0.0;
    if(fabs(y) < 0.1) y = 0.0;
    
    drive.ArcadeDrive(y, x);
  }, {&drive}));

  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here
  //When button on D-pad left strafe robot left
  controller.POV(270).OnTrue(frc2::cmd::RunOnce([this]() {
    drive.StrafeLeft();
  }, {}));
  
  //When button on D-pad left not pressed then stop
  controller.POV(270).OnFalse(frc2::cmd::RunOnce([this]() {
    drive.StopStrafing();
  }, {}));

  //When button on D-pad right strafe robot right
  controller.POV(90).OnTrue(frc2::cmd::RunOnce([this]() {
    drive.StrafeRight();
  }, {}));

  //When button D-pad right not pressed then stop
  controller.POV(90).OnFalse(frc2::cmd::RunOnce([this]() {
    drive.StopStrafing();
  }, {}));

  controller.A().OnTrue(frc2::cmd::RunOnce([this]() {
    telescope.SetTelescopePosition(0.0_m);
  }, {&telescope}));
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  return frc2::cmd::Sequence(
    frc2::cmd::Sequence(
      frc2::cmd::RunOnce([this]() {
        drive.ArcadeDrive(0.5, 0.0);
      }, {&drive}),
      frc2::cmd::Wait(2.0_s),
      frc2::cmd::RunOnce([this]() {
        drive.ArcadeDrive(0.0, 0.0);
      }, {&drive}))
    );

}
