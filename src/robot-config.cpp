#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftFlyMotor = motor(PORT1, ratio6_1, false);
motor RightFlyMotor = motor(PORT2, ratio6_1, false);
controller Controller1 = controller(primary);
bumper BumperB = bumper(Brain.ThreeWirePort.B);
digital_out LaunchPiston = digital_out(Brain.ThreeWirePort.A);
encoder LeftFlyEncoder = encoder(Brain.ThreeWirePort.C);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}