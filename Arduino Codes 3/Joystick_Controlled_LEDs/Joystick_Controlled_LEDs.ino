/*********************************************************
Project Title: Collision Detection
Organisation: Soham Academy Of Human Excellence
Website: https://ria.sohamacademy.org/
*********************************************************/
// Arduino pin numbers
const int SW_pin = 2; // digital pin 2 connected to SW of Joystick Module
const int X_pin = A0; // analog pin A0 connected to VRx of Joystick module
const int Y_pin = A1; // analog pin A1 connected to VRy of Joystick module

#define LEFT_LED 13
#define UP_LED 12
#define RIGHT_LED 11
#define DOWN_LED 10

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
  pinMode(UP_LED , OUTPUT);
  pinMode(RIGHT_LED , OUTPUT);
  pinMode(LEFT_LED , OUTPUT);
  pinMode(DOWN_LED , OUTPUT);
}

void loop() {
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n\n");
  delay(500);
  
  if (analogRead(X_pin) == 0) {
    digitalWrite(UP_LED , LOW);
    digitalWrite(LEFT_LED ,HIGH);
    digitalWrite(RIGHT_LED , LOW);
    digitalWrite(DOWN_LED , LOW);
  } else if (analogRead(X_pin) == 1023) {
    digitalWrite(UP_LED , LOW);
    digitalWrite(LEFT_LED ,LOW);
    digitalWrite(RIGHT_LED , HIGH);
    digitalWrite(DOWN_LED , LOW);
  }

  else if (analogRead(Y_pin) == 0) {
    digitalWrite(UP_LED , HIGH);
    digitalWrite(LEFT_LED ,LOW);
    digitalWrite(RIGHT_LED , LOW);
    digitalWrite(DOWN_LED , LOW);
  }

  else if (analogRead(Y_pin) == 1023) {
    digitalWrite(UP_LED , LOW);
    digitalWrite(LEFT_LED ,LOW);
    digitalWrite(RIGHT_LED , LOW);
    digitalWrite(DOWN_LED , HIGH);
  }

  else if (digitalRead(SW_pin) == 0) {
    digitalWrite(UP_LED , HIGH);
    digitalWrite(LEFT_LED , HIGH);
    digitalWrite(RIGHT_LED , HIGH);
    digitalWrite(DOWN_LED , HIGH);
  }
  else {
    digitalWrite(UP_LED , LOW);
    digitalWrite(LEFT_LED , LOW);
    digitalWrite(RIGHT_LED , LOW);
    digitalWrite(DOWN_LED , LOW);
  }
}
