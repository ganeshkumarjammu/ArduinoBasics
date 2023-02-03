
 
// constants won't change:
const int LED_PIN = 3;     // the number of the LED pin
const int BUTTON_PIN = 7;  // the number of the button pin

const long BLINK_INTERVAL = 1000;   // interval at which to blink LED (milliseconds)

// Variables will change:
int ledState = LOW;   // ledState used to set the LED

int previousButtonState = LOW; // will store last time button was updated

void setup() {
  Serial.begin(9600);

  // set the digital pin as output:
  pinMode(LED_PIN, OUTPUT);

  // set the digital pin as an input:
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  // if the LED is off turn it on and vice-versa:
  ledState = (ledState == LOW) ? HIGH : LOW;

  // set the LED with the ledState of the variable:
  digitalWrite(LED_PIN, ledState);

  delay(BLINK_INTERVAL); // If button is pressed during this time, Arduino CANNOT detect

  int currentButtonState = digitalRead(BUTTON_PIN);

  if(currentButtonState != previousButtonState) {
    // print out the state of the button:
    Serial.println(currentButtonState);

    // save the last state of button
    previousButtonState = currentButtonState;
  }

  // DO OTHER WORKS HERE
}
