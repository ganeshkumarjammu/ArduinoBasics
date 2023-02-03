// constants won't change
const int POTENTIOMETER_PIN = A0; // Arduino pin connected to Potentiometer pin
const int LED_PIN           = 3;  // Arduino pin connected to LED's pin
const int ANALOG_THRESHOLD  = 500;

void setup() {
  pinMode(LED_PIN, OUTPUT); // set arduino pin to output mode
}

void loop() {
  int analogValue = analogRead(POTENTIOMETER_PIN); // read the input on analog pin

  if(analogValue > ANALOG_THRESHOLD)
    digitalWrite(LED_PIN, HIGH); // turn on LED
  else
    digitalWrite(LED_PIN, LOW);  // turn off LED
}
