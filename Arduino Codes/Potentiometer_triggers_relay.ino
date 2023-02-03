// constants won't change
const int POTENTIOMETER_PIN = A0; // Arduino pin connected to Potentiometer pin
const int RELAY_PIN         = 3;  // Arduino pin connected to Relay's pin
const int ANALOG_THRESHOLD  = 500;

void setup() {
  pinMode(RELAY_PIN, OUTPUT); // set arduino pin to output mode
}

void loop() {
  int analogValue = analogRead(POTENTIOMETER_PIN); // read the input on analog pin

  if(analogValue > ANALOG_THRESHOLD)
    digitalWrite(RELAY_PIN, HIGH); // turn on Relay
  else
    digitalWrite(RELAY_PIN, LOW);  // turn off Relay
}
