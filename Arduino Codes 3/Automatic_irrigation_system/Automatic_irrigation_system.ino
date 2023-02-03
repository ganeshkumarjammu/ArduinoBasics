#define RELAY_PIN    2  // Arduino pin that connects to relay
#define MOISTURE_PIN A0 // Arduino pin that connects to AOUT pin of moisture sensor

#define THRESHOLD 100 // CHANGE YOUR THRESHOLD HERE

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  int value = analogRead(MOISTURE_PIN); // read the analog value from sensor

  if (value < THRESHOLD) {
    Serial.print("The soil is DRY => turn pump ON");
    digitalWrite(RELAY_PIN, HIGH);
  } else {
    Serial.print("The soil is WET => turn pump OFF");
    digitalWrite(RELAY_PIN, LOW);
  }

  Serial.print(" (");
  Serial.print(value);
  Serial.println(")");

  delay(500);
}
