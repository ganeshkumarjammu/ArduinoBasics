#include <AccelStepper.h>

#define DEG_PER_STEP 1.8
#define STEP_PER_REVOLUTION (360 / DEG_PER_STEP)

AccelStepper stepper(AccelStepper::FULL4WIRE, 7, 6, 5, 4);

long moveToPosition = STEP_PER_REVOLUTION;

void setup() {
  Serial.begin(9600);

  stepper.setAcceleration(200.0); // set acceleration
  stepper.setSpeed(200);          // set initial speed
  stepper.setCurrentPosition(0);  // set position to 0

  stepper.moveTo(STEP_PER_REVOLUTION); // move motor one revolution, in clockwise direction
  Serial.println("Motor moving in clockwise direction");
}

void loop() {
  if (stepper.distanceToGo() == 0) {
    Serial.println("Motor is stopped");
    delay(5000); // stop 5 seconds
    stepper.setCurrentPosition(0); // reset position to 0
    moveToPosition = -1 * moveToPosition; // reverse direction

    stepper.moveTo(moveToPosition); // move motor one revolution

    if (stepper.distanceToGo() > 0)
      Serial.println("Motor moving in clockwise direction");
    else if (stepper.distanceToGo() < 0)
      Serial.println("Motor moving in anticlockwise direction");
  }

  // Serial.print(F("position: "));
  // Serial.println(stepper.currentPosition());

  stepper.run(); // MUST be called as frequently as possible
}
