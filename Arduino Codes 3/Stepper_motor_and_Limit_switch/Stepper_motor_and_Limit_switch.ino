#include <ezButton.h>
#include <AccelStepper.h>

#define MAX_POSITION 0x7FFFFFFF // maximum of position we can set (long type)

ezButton limitSwitch(A0); // create ezButton object that attach to pin A0;

AccelStepper stepper(AccelStepper::FULL4WIRE, 7, 6, 5, 4);

bool isStopped = false;

void setup() {
  Serial.begin(9600);

  limitSwitch.setDebounceTime(50); // set debounce time to 50 milliseconds

  stepper.setMaxSpeed(500.0);   // set the maximum speed
  stepper.setAcceleration(50.0); // set acceleration
  stepper.setSpeed(100);         // set initial speed
  stepper.setCurrentPosition(0); // set position

  stepper.moveTo(MAX_POSITION);
}

void loop() {
  limitSwitch.loop(); // MUST call the loop() function first

  if (limitSwitch.isPressed()) {
    Serial.println(F("The limit switch: TOUCHED"));
    isStopped = true;
  }

  if (isStopped == false) {
    // without this part, the move will stop after reaching maximum position
    if (stepper.distanceToGo() == 0) { // if motor moved to the maximum position
      stepper.setCurrentPosition(0);   // reset position to 0
      stepper.moveTo(MAX_POSITION);       // move the motor to maximum position again
    }

    stepper.run(); // MUST be called in loop() function
  } else {
    // without calling stepper.run() function, motor stops immediately
    // NOTE: stepper.stop() function does NOT stops motor immediately
    Serial.println(F("The stepper motor is STOPPED"));
  }
}
