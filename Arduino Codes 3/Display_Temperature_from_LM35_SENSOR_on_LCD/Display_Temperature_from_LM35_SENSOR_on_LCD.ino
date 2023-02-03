#include <LiquidCrystal_I2C.h> // LCD I2C library

#define ADC_VREF_mV    5000.0 // in millivolt
#define ADC_RESOLUTION 1024.0

#define PIN_LM35 A0 // pin connected to LM35 temperature sensor

LiquidCrystal_I2C lcd(0x3F, 16, 2);  // LCD I2C address 0x27, 16 column and 2 rows

void setup() {
  Serial.begin(9600);

  lcd.init();      // initialize the lcd
  lcd.backlight(); // open the backlight
}

void loop() {
  int adcVal = analogRead(PIN_LM35);
  // convert the ADC value to voltage in millivolt
  float milliVolt = adcVal * (ADC_VREF_mV / ADC_RESOLUTION);
  // convert the voltage to the temperature in Celsius
  float tempC = milliVolt / 10;
  float tempF = tempC * 9 / 5 + 32; // convert Celsius to Fahrenheit

  lcd.clear();
  lcd.setCursor(0, 0); // start to print at the first row
  lcd.print(tempC);    // print the temperature in Celsius
  lcd.print("°C");
  lcd.setCursor(0, 1); // start to print at the second row
  lcd.print(tempF);    // print the temperature in Fahrenheit
  lcd.print("°F");

  // print the temperature to Serial Monitor
  Serial.print(tempC);
  Serial.print("°C ~ ");
  Serial.print(tempF);
  Serial.println("°F");

  delay(500);
}
