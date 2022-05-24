using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LeftFlyMotor;
extern motor RightFlyMotor;
extern controller Controller1;
extern bumper BumperB;
extern digital_out LaunchPiston;
extern rotation LeftFlyEncoder;
extern rotation RightFlyEncoder;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );