#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define SCREEN_WIDTH 128 // OLED display width,  in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define SENSOR_PIN 2 // Arduino pin connected to DS18B20 sensor's DQ pin

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1); // create SSD1306 display object connected to I2C
OneWire oneWire(SENSOR_PIN);         // setup a oneWire instance
DallasTemperature tempSensor(&oneWire); // pass oneWire to DallasTemperature library

String tempString;

void setup() {
  Serial.begin(9600);

  // initialize OLED display with address 0x3C for 128x64
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }

  delay(2000);         // wait for initializing
  oled.clearDisplay(); // clear display

  oled.setTextSize(2);          // text size
  oled.setTextColor(WHITE);     // text color
  oled.setCursor(0, 10);        // position to display

  tempSensor.begin();     // initialize the sensor
  tempString.reserve(10); // to avoid fragmenting memory when using String
}

void loop() {
  tempSensor.requestTemperatures();             // send the command to get temperatures
  float tempCelsius = tempSensor.getTempCByIndex(0);  // read temperature in Celsius

  tempString  = String(tempCelsius, 2); // two decimal places
  tempString += "°C";

  Serial.println(tempString); // print the temperature in Celsius to Serial Monitor
  oledDisplayCenter(tempString);
}

void oledDisplayCenter(String text) {
  int16_t x1;
  int16_t y1;
  uint16_t width;
  uint16_t height;

  oled.getTextBounds(text, 0, 0, &x1, &y1, &width, &height);

  // display on horizontal and vertical center
  oled.clearDisplay(); // clear display
  oled.setCursor((SCREEN_WIDTH - width) / 2, (SCREEN_HEIGHT - height) / 2);
  oled.println(text); // text to display
  oled.display();
}
