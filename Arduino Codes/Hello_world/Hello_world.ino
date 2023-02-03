
#include <Servo.h>
#include <LiquidCrystal.h>

#define MAX_COUNT 180

Servo servo;
LiquidCrystal lcd(3, 4, 5, 6, 7, 8);
int loop_count = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  servo.attach(9); 

  Serial.println("This is setup code");
}

void loop() {
  loop_count++;

  Serial.print("This is loop code, count: ");
  Serial.println(loop_count);

  lcd.print("Hello World!");
  servo.write(loop_count);

  if(loop_count >= MAX_COUNT)
    loop_count = 0;

  delay(1000);
}
