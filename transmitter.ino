#define laserPin 13 // Pin connected to the laser module

void setup() {
  pinMode(laserPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char inputChar = Serial.read(); // Read character from Serial Monitor
    transmitData(inputChar);
  }
}

void transmitData(char data) {
  // Convert character to binary representation
  byte binaryData = data;
  
  // Send each bit of binary data by modulating laser intensity
  for (int i = 7; i >= 0; i--) {
    int bit = (binaryData >> i) & 1;
    digitalWrite(laserPin, bit); // Modulate laser intensity based on the bit
    delay(50); // Adjust delay as needed
  }
}
/////transmitter