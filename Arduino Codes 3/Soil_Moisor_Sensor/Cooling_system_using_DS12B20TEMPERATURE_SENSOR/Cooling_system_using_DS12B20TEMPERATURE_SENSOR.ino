#include <OneWire.h>
#include <DallasTemperature.h>

const int TEMP_THRESHOLD_UPPER = 25; // upper threshold of temperature, change to your desire value
const int TEMP_THRESHOLD_LOWER = 20; // lower threshold of temperature, change to your desire value

const int SENSOR_PIN    = 2; // Arduino pin connected to DS18B20 sensor's DQ pin
const int RELAY_FAN_PIN = A5; // Arduino pin connected to relay which connected to fan

OneWire oneWire(SENSOR_PIN);         // setup a oneWire instance
DallasTemperature sensors(&oneWire); // pass oneWire to DallasTemperature library

float temperature;    // temperature in Celsius

void setup()
{
  Serial.begin(9600); // initialize serial
  sensors.begin();    // initialize the sensor
  pinMode(RELAY_FAN_PIN, OUTPUT); // initialize digital pin as an output
}

void loop()
{
  sensors.requestTemperatures();             // send the command to get temperatures
  temperature = sensors.getTempCByIndex(0);  // read temperature in Celsius

  if(temperature > TEMP_THRESHOLD_UPPER){
    Serial.println("The fan is turned on");
    digitalWrite(RELAY_FAN_PIN, HIGH); // turn on
  } else if(temperature < TEMP_THRESHOLD_LOWER){
    Serial.println("The fan is turned off");
    digitalWrite(RELAY_FAN_PIN, LOW); // turn on
  }

  delay(500);
}
