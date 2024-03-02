#define solarPanelPin A0 // Analog pin connected to the solar panel

void setup() {
  pinMode(solarPanelPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  String receivedData = receiveData();
  Serial.println(receivedData);
  delay(1000); // Adjust delay as needed
}

String receiveData() {
  String receivedText = "";
  for (int i = 0; i < 8; i++) {
    byte binaryData = 0;
    for (int j = 0; j < 8; j++) {
      int sensorValue = analogRead(solarPanelPin);
      int bit = sensorValue > 512 ? 1 : 0; // Threshold for distinguishing 1s and 0s
      binaryData |= (bit << j);
      delay(50); // Delay for sampling
    }
    receivedText += char(binaryData);
  }
  return receivedText;
}
