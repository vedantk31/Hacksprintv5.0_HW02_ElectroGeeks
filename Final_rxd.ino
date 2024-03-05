const int analogPin = A0; 
const int threshold = 409; 
unsigned long startTime = 0;
bool isTiming = false; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  int analogValue = analogRead(analogPin); 
  if (analogValue > threshold) { 
    if (!isTiming) { 
      startTime = millis();
      isTiming = true;
    }
  } else { 
    if (isTiming) { 
      unsigned long duration = millis() - startTime; 
      if (duration >= 1000 && duration < 2000) { 
        Serial.println("Recieved: Good afternoon");
      } else if (duration >= 2000 && duration < 3000) { 
        Serial.println("Recieved: Sir");
      } else if (duration >= 3000) { 
        Serial.println("Recieved: LiFi communication is succesfull");
      }
      isTiming = false;
    }
  }
  delay(10); 
}
//Reciever code