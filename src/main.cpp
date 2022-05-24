/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\alexp                                            */
/*    Created:      Fri May 20 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftFlyMotor         motor         1               
// RightFlyMotor        motor         2               
// Controller1          controller                    
// BumperB              bumper        B               
// LaunchPiston         digital_out   A               
// LeftFlyEncoder       rotation      3               
// RightFlyEncoder      rotation      4               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <iostream>

using namespace vex;

void RPMValue(){
     int LeftFlySpeed = LeftFlyEncoder.velocity(rpm);
     int RightFlySpeed = RightFlyEncoder.velocity(rpm);
     using namespace std;
     cout <<"Current RPM: Left:" << LeftFlySpeed << " | Right:" << RightFlySpeed << "\n";
    wait(0.1, sec);
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while(true){
    if(BumperB.pressing()){
      LaunchPiston.set(true);
      wait(50,msec);
      LaunchPiston.set(false);
    }
    if(Controller1.ButtonA.pressing()){
      int leftflyrpm = 100; 
      int rightflyrpm = 100;
      LeftFlyMotor.setVelocity(leftflyrpm, rpm);
      RightFlyMotor.setVelocity(rightflyrpm, rpm);
      LeftFlyMotor.spin(forward);
      RightFlyMotor.spin(forward);
    }
    if(Controller1.ButtonB.pressing()){
      LeftFlyMotor.stop();
      RightFlyMotor.stop();
    }
    if(Controller1.ButtonX.pressing()){
     // Brain.SDcard.savefile("test.h", txt,);
    }
   RPMValue(); 
  }
  
}

