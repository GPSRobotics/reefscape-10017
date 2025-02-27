// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/Autos.h"


RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  controller.POV(270).OnTrue(frc2::cmd::RunOnce([this]() {
    drive.StrafeLeft();
  }, {}));

  controller.POV(270).OnFalse(frc2::cmd::RunOnce([this]() {
    drive.StopStrafing();
  }, {}));

  controller.POV(90).OnTrue(frc2::cmd::RunOnce([this]() {
    drive.StrafeRight();
  }, {}));

  controller.POV(90).OnFalse(frc2::cmd::RunOnce([this]() {
    drive.StopStrafing();
  }, {}));

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
/*
  // Schedule `ExampleCommand` when `exampleCondition` changes to `true`
  frc2::Trigger([this] {
    return m_subsystem.ExampleCondition();
  }).OnTrue(ExampleCommand(&m_subsystem).ToPtr());

  // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
  // pressed, cancelling on release.
  m_driverController.B().WhileTrue(m_subsystem.ExampleMethodCommand());
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);*/
}
