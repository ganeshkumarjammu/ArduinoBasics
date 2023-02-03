#include <SD.h>

#define PIN_SPI_CS 4

File myFile;
int myInt = -52;
float myFloat = -12.7;
String myString = "HELLO";
char myCharArray[] = "ArduinoGetStarted.com";
byte myByteArray[] = {'1', '2', '3', '4', '5'};

void setup() {
  Serial.begin(9600);

  if (!SD.begin(PIN_SPI_CS)) {
    Serial.println(F("SD CARD FAILED, OR NOT PRESENT!"));
    while (1); // don't do anything more:
  }

  Serial.println(F("SD CARD INITIALIZED."));
  Serial.println(F("--------------------"));
  SD.remove("arduino.txt"); // delete the file if existed

  // create new file by opening file for writing
  myFile = SD.open("arduino.txt", FILE_WRITE);

  if (myFile) {
    myFile.println(myInt);    // write int variable to SD card in line
    myFile.println(myFloat);  // write float variable to SD card in line
    myFile.println(myString); // write String variable to SD card in line
    myFile.println(myCharArray); // write char array to SD card in line
    myFile.write(myByteArray, 5);
    myFile.write("\n"); // new line

    for (int i = 0; i < 5; i++) {
      myFile.write(myByteArray[i]); // new line

      if (i < 4)
        myFile.write(","); // comma
    }
    myFile.write("\n"); // new line

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
