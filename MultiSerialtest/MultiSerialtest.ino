/*
  Multiple Serial test

  Receives from the main serial port, sends to the others.
  Receives from serial port 1, sends to the main serial (Serial 0).

  This example works only with boards with more than one serial like Arduino Mega, Due, Zero etc.

  The circuit:
  - any serial device attached to Serial port 1
  - Serial Monitor open on Serial port 0

  created 30 Dec 2008
  modified 20 May 2012
  by Tom Igoe & Jed Roach
  modified 27 Nov 2015
  by Arturo Guadalupi

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/MultiSerialMega
*/


void setup() {
  // initialize both serial ports:
  Serial.println("Beginning serial+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
  Serial.begin(9600);
  Serial.println("---------------------------------------------------------------------Begun serial");
//  Serial1.begin(9600);
  delay(10000);
}

void loop() {
  // read from port 1, send to port 0:
  Serial.println("eerrrppppoo");
//  Serial.println("Before IF");
  if (Serial.available()) {
//    Serial.println("Before reading");
    String inByte = Serial.readString();
//    Serial.println("After reading");
    if(inByte[0] == 'T') {
      Serial.println(inByte);
    }
    else if(inByte[0] == 'C') {
      Serial.println("E");
    }
//    Serial.println("After printing reading");
  }
//  Serial.println("After loop once");

  // read from port 0, send to port 1:
//  if (Serial.available()) {
//    int inByte = Serial.read();
//    Serial1.println(inByte);
//  }
}
