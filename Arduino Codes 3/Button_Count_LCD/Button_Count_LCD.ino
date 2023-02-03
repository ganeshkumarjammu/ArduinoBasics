#include <LiquidCrystal_I2C.h>
#include <ezButton.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2); // I2C address 0x3F, 16 column and 2 rows
ezButton button(13);  // create ezButton object that attach to pin 13;
unsigned long lastCount = 0;

void setup() {
  Serial.begin(9600);

  lcd.init();               // initialize the lcd
  lcd.backlight();          // open the backlight

  button.setDebounceTime(50); // set debounce time to 50 milliseconds
  button.setCountMode(COUNT_FALLING);
}

void loop() {
  button.loop(); // MUST call the loop() function first

  unsigned long count = button.getCount();
  if (lastCount != count) {
    Serial.println(count); // print count to Serial Monitor

    lcd.clear();
    lcd.setCursor(0, 0); // start to print at the first row
    lcd.print("Count: ");
    lcd.print(count);

    lastCount != count;
  }
}
