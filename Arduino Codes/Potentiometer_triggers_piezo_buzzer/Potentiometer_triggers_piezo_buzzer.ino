// constants won't change
const int POTENTIOMETER_PIN = A0; // Arduino pin connected to Potentiometer pin
const int BUZZER_PIN        = 3; // Arduino pin connected to Buzzer's pin
const int ANALOG_THRESHOLD  = 500;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT); // set arduino pin to output mode
}

void loop() {
  int analogValue = analogRead(POTENTIOMETER_PIN); // read the input on analog pin

  if(analogValue > ANALOG_THRESHOLD)
    digitalWrite(BUZZER_PIN, HIGH); // turn on Piezo Buzzer
  else
    digitalWrite(BUZZER_PIN, LOW);  // turn off Piezo Buzzer
}
