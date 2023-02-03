#include <Keypad.h>

const int RELAY_PIN  = A5; // the Arduino pin, which connects to the IN pin of relay
const int ROW_NUM    = 4; // four rows
const int COLUMN_NUM = 4; // four columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

byte pin_rows[ROW_NUM] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

const String password_1 = "1234ABC"; // change your password here
const String password_2 = "5642CD";  // change your password here
const String password_3 = "4545B";   // change your password here
String input_password;

void setup() {
  Serial.begin(9600);
  input_password.reserve(32); // maximum input characters is 33, change if needed
  pinMode(RELAY_PIN, OUTPUT); // initialize pin as an output.
  digitalWrite(RELAY_PIN, LOW); // lock the door
}

void loop() {
  char key = keypad.getKey();

  if (key){
    Serial.println(key);

    if(key == '*') {
      input_password = ""; // reset the input password
    } else if(key == '#') {
      if(input_password == password_1 || input_password == password_2 || input_password == password_3) {
        Serial.println("The password is correct, unlocking the door in 20 seconds");
        digitalWrite(RELAY_PIN, HIGH);  // unlock the door for 20 seconds
        delay(20000);
        digitalWrite(RELAY_PIN, LOW); // lock the door
      } else {
        Serial.println("The password is incorrect, try again");
      }

      input_password = ""; // reset the input password
    } else {
      input_password += key; // append new character to input password string
    }
  }
}
