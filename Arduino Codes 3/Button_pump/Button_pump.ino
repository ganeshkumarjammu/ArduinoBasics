#include <ezButton.h> // include ezButton library
#include <ezOutput.h> // include ezOutput library

ezOutput pump(A5);    // create ezOutput object attached to pin A5
ezButton button(12);  // create ezButton object attached to pin 12

void setup() {
  Serial.begin(9600);
  button.setDebounceTime(50); // set debounce time to 50 milliseconds
  pump.low(); // turn pump off
}

void loop() {
  pump.loop();   // MUST call the loop() function first
  button.loop(); // MUST call the loop() function first

  if (button.isPressed()) {
    Serial.println("Pump is started");
    pump.low();
    pump.pulse(10000); // turn on for 10000 milliseconds ~ 10 seconds
    // after 10 seconds, pump will be turned off by pump.loop() function
  }
}
