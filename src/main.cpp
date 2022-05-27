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
// StartPistonButton    bumper        B               
// LaunchPiston         digital_out   A               
// LeftFlyEncoder       rotation      3               
// RightFlyEncoder      rotation      4               
// StartFlyButton       bumper        C               
// StartFlyEncoder      bumper        D               
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

}
void FlyStop(){
  RightFlyMotor.stop(coast);
  LeftFlyMotor.stop(coast);
}
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  //Defined Variables
  bool FlyToggle = false;
  bool FlyLatch = false;
  bool EncoderToggle = false;
  bool EncoderLatch = false;
  //Main Function Loop
  while(true){
    if(StartFlyButton){
      if(!FlyLatch){
        FlyToggle = !FlyToggle;
        FlyLatch = true;
      }
    }
    else{
      FlyLatch = false; 
    }
   if(FlyToggle == true){
    FlyControl(200,200); //Left RPM, Right RPM
  }
   else{
    FlyStop();
   }
  if(StartFlyEncoder){
    if(!EncoderToggle){
      EncoderToggle = !EncoderToggle;
      EncoderLatch = true;
    }
    else {
    EncoderLatch = false;
    }
    if(EncoderToggle == true){
      RPMValue(25); //In Milisecends
    }
  }
  
   }
}
