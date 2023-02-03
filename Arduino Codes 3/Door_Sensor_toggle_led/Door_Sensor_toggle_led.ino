
// constants won't change
const int DOOR_SENSOR_PIN = 13; // Arduino pin connected to door sensor's pin
const int LED_PIN         = 3;  // Arduino pin connected to LED's pin

// variables will change:
int ledState = LOW;   // the current state of LED
int lastDoorState;    // the previous state of door sensor
int currentDoorState; // the current state of door sensor

void setup() {
  Serial.begin(9600);                     // initialize serial
  pinMode(DOOR_SENSOR_PIN, INPUT_PULLUP); // set arduino pin to input pull-up mode
  pinMode(LED_PIN, OUTPUT);               // set arduino pin to output mode

  currentDoorState = digitalRead(DOOR_SENSOR_PIN);
}

void loop() {
  lastDoorState    = currentDoorState;             // save the last state
  currentDoorState = digitalRead(DOOR_SENSOR_PIN); // read new state

  if (lastDoorState == HIGH && currentDoorState == LOW) { // state change: HIGH -> LOW
    Serial.println("The door-closing event is detected");

    // toggle state of LED
    ledState = !ledState;

    // control LED arccoding to the toggled state
    digitalWrite(LED_PIN, ledState); 
  }
}


if(ledState == LOW)
  ledState = HIGH;
else
  ledState = LOW;
