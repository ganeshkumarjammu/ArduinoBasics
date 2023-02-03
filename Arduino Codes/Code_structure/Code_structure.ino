/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-serial-monitor
 */

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("ArduinoGetStarted.com");
  delay(1000);
}
