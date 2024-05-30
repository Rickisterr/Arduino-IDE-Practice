char* fileName = "/datalog.txt";

void ReadFile(const char * path){
  // open the file for reading:
  myFile = SD.open(path);
  if (myFile) {
     Serial.printf("Reading file from %s\n", path);
     // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close(); // close the file:
  } 
  else {
    // if the file didn't open, print an error:
    Serial.println("error opening datalog.txt");
  }
}

void setup() {
  // put your setup code here, to run once:
  ReadFile(fileName);
}

void loop() {
  // put your main code here, to run repeatedly:

}
