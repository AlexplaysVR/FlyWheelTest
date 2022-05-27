using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LeftFlyMotor;
extern motor RightFlyMotor;
extern controller Controller1;
extern bumper StartPistonButton;
extern digital_out LaunchPiston;
extern rotation LeftFlyEncoder;
extern rotation RightFlyEncoder;
extern bumper StartFlyButton;
extern bumper StartFlyEncoder;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );