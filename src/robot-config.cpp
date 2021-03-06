#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftFlyMotor = motor(PORT1, ratio18_1, true);
motor RightFlyMotor = motor(PORT2, ratio18_1, false);
controller Controller1 = controller(primary);
bumper StartPistonButton = bumper(Brain.ThreeWirePort.B);
digital_out LaunchPiston = digital_out(Brain.ThreeWirePort.A);
rotation LeftFlyEncoder = rotation(PORT3, true);
rotation RightFlyEncoder = rotation(PORT4, true);
bumper StartFlyButton = bumper(Brain.ThreeWirePort.C);
bumper StartFlyEncoder = bumper(Brain.ThreeWirePort.D);

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