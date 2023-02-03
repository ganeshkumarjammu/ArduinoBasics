// constants won't change
const int DOOR_SENSOR_PIN = 13; // Arduino pin connected to door sensor's pin
const int RELAY_PIN       = 3;  // Arduino pin connected to relay's pin

// variables will change:
int relayState = LOW; // the current state of relay
int lastDoorState;    // the previous state of door sensor
int currentDoorState; // the current state of door sensor

void setup() {
  Serial.begin(9600);                     // initialize serial
  pinMode(DOOR_SENSOR_PIN, INPUT_PULLUP); // set arduino pin to input pull-up mode
  pinMode(RELAY_PIN, OUTPUT);             // set arduino pin to output mode

  currentDoorState = digitalRead(DOOR_SENSOR_PIN);
}

void loop() {
  lastDoorState    = currentDoorState;             // save the last state
  currentDoorState = digitalRead(DOOR_SENSOR_PIN); // read new state

  if (lastDoorState == HIGH && currentDoorState == LOW) { // state change: HIGH -> LOW
    Serial.println("The door-closing event is detected");

    // toggle state of relay
    relayState = !relayState;

    // control relay arccoding to the toggled state
    digitalWrite(RELAY_PIN, relayState); 
  }
}


if(relayState == LOW)
  relayState = HIGH;
else
  relayState = LOW;
