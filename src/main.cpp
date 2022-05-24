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
int Time = 0;
bool Spinning = false;
int LeftFlySpeed = LeftFlyEncoder.velocity(rpm);
int RightFlySpeed = RightFlyEncoder.velocity(rpm);
int AbsoluteRightFlySpeed = abs(RightFlySpeed);
int AbsoluteLeftFlySpeed = abs(LeftFlySpeed);
void RPMValue(int repeatinterval){
     using namespace std;
     cout << Time << " Left: " << LeftFlySpeed << " Right: " << RightFlySpeed << "\n";
    wait(repeatinterval, msec);
     Time += repeatinterval;
}
void FlyControl(int leftflyrpm, int rightflyrpm){
      if(BumperB.pressing()){
      LaunchPiston.set(true);
      wait(200,msec);
      LaunchPiston.set(false);
    }
    if(Controller1.ButtonA.pressing()){
      LeftFlyMotor.setVelocity(leftflyrpm, rpm);
      RightFlyMotor.setVelocity(rightflyrpm, rpm);
      LeftFlyMotor.spin(forward);
      RightFlyMotor.spin(forward);
    }
    if(Controller1.ButtonB.pressing()){
      LeftFlyMotor.stop();
      RightFlyMotor.stop();
      wait(5, sec);
    }
}
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!

  vexcodeInit();
  while(true){
   FlyControl(200, 200); //Left RPM, Right RPM
   int AverageFlyRPM = (AbsoluteRightFlySpeed + AbsoluteLeftFlySpeed) / 2;
   if(AverageFlyRPM < 1){
     Spinning = false;
   }
   else if(AverageFlyRPM > 1){
     Spinning = true;
   }
   if(Spinning == true){
    RPMValue(25); //In Milisecends
   }
  }
  
}

