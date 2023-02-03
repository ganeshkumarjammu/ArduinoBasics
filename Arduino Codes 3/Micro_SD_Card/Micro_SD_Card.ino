#include <SD.h>

#define PIN_SPI_CS 4

File myFile;

void setup() {
  Serial.begin(9600);

  if (!SD.begin(PIN_SPI_CS)) {
    Serial.println(F("SD CARD FAILED, OR NOT PRESENT!"));
    while (1); // don't do anything more:
  }

  Serial.println(F("SD CARD INITIALIZED."));

  if (!SD.exists("arduino.txt")) {
    Serial.println(F("arduino.txt doesn't exist. Creating arduino.txt file..."));
    // create a new file by opening a new file and immediately close it
    myFile = SD.open("arduino.txt", FILE_WRITE);
    myFile.close();
  }

  // recheck if file is created or not
  if (SD.exists("arduino.txt"))
    Serial.println(F("arduino.txt exists on SD Card."));
  else
    Serial.println(F("arduino.txt doesn't exist on SD Card."));
}

void loop() {
}



/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-micro-sd-card
 */

#include <SD.h>

#define PIN_SPI_CS 4

File myFile;

void setup() {
  Serial.begin(9600);

  if (!SD.begin(PIN_SPI_CS)) {
    Serial.println(F("SD CARD FAILED, OR NOT PRESENT!"));
    while (1); // don't do anything more:
  }

  Serial.println(F("SD CARD INITIALIZED."));

  // open file for writing
  myFile = SD.open("arduino.txt", FILE_WRITE);

  if (myFile) {
    myFile.println("Created by ArduinoGetStarted.com"); // write a line to Arduino
    myFile.println("Learn Arduino and SD Card"); // write another  line to Arduino
    myFile.close();
  } else {
    Serial.print(F("SD Card: error on opening file arduino.txt"));
  }

  // open file for reading
  myFile = SD.open("arduino.txt", FILE_READ);
  if (myFile) {
    while (myFile.available()) {
      char ch = myFile.read(); // read characters one by one from Micro SD Card
      Serial.print(ch); // print the character to Serial Monitor
    }
    myFile.close();
  } else {
    Serial.print(F("SD Card: error on opening file arduino.txt"));
  }
}

void loop() {
}



/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-micro-sd-card
 */

#include <SD.h>

#define PIN_SPI_CS 4

File myFile;

void setup() {
  Serial.begin(9600);

  if (!SD.begin(PIN_SPI_CS)) {
    Serial.println(F("SD CARD FAILED, OR NOT PRESENT!"));
    while (1); // don't do anything more:
  }

  Serial.println(F("SD CARD INITIALIZED."));

  // open file for writing
  myFile = SD.open("arduino.txt", FILE_WRITE);

  if (myFile) {
    myFile.println("Created by ArduinoGetStarted.com"); // write a line to Arduino
    myFile.println("Learn Arduino and SD Card"); // write another  line to Arduino
    myFile.close();
  } else {
    Serial.print(F("SD Card: error on opening file arduino.txt"));
  }

  // open file for reading
  myFile = SD.open("arduino.txt", FILE_READ);
  if (myFile) {
    int line_count = 0;
    while (myFile.available()) {
      char line[100]; // maximum is 100 characters, change it if needed
      int line_length = myFile.readBytesUntil('\n', line, 100); // read line-by-line from Micro SD Card
      line_count++;

      Serial.print(F("Line "));
      Serial.print(line_count);
      Serial.print(F(": "));
      Serial.write(line, line_length); // print the character to Serial Monitor
      // \n character is escaped by readBytesUntil function
      Serial.write('\n'); // print a new line charactor
    }
    myFile.close();
  } else {
    Serial.print(F("SD Card: error on opening file arduino.txt"));
  }
}

void loop() {
}



/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-micro-sd-card
 */

#include <SD.h>

#define PIN_SPI_CS 4

File myFile;

void setup() {
  Serial.begin(9600);

  if (!SD.begin(PIN_SPI_CS)) {
    Serial.println(F("SD CARD FAILED, OR NOT PRESENT!"));
    while (1); // don't do anything more:
  }

  Serial.println(F("SD CARD INITIALIZED."));
  SD.remove("arduino.txt"); // delete the file if existed

  // create new file by opening file for writing
  myFile = SD.open("arduino.txt", FILE_WRITE);

  if (myFile) {
    myFile.println("Created by ArduinoGetStarted.com"); // write a line to Arduino
    myFile.println("Learn Arduino and SD Card"); // write another  line to Arduino
    myFile.close();
  } else {
    Serial.print(F("SD Card: error on opening file arduino.txt"));
  }

  // open file for reading
  myFile = SD.open("arduino.txt", FILE_READ);
  if (myFile) {
    while (myFile.available()) {
      char ch = myFile.read(); // read characters one by one from Micro SD Card
      Serial.print(ch); // print the character to Serial Monitor
    }
    myFile.close();
  } else {
    Serial.print(F("SD Card: error on opening file arduino.txt"));
  }
}

void loop() {
}
