#define LASER_PIN 7 // Digital pin connected to the laser
#define SIGNAL_DURATION 1000  // Duration of logic 1 signal (in milliseconds)

char input;

void setup() {
  pinMode(LASER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    input = Serial.read();
  }

  if (input == '1') {
    // Send "Hello" signal
    digitalWrite(LASER_PIN, HIGH);
    delay(SIGNAL_DURATION);
    digitalWrite(LASER_PIN, LOW);
    Serial.println("Sent: Hello");
  } else if (input == '2') {
    // Send "World" signal
    digitalWrite(LASER_PIN, HIGH);
    delay(2 * SIGNAL_DURATION);
    digitalWrite(LASER_PIN, LOW);
    Serial.println("Sent: World");
  } else if (input == '3') {
    // Send "Li-Fi communication successful!" signal
    digitalWrite(LASER_PIN, HIGH);
    delay(3 * SIGNAL_DURATION);
    digitalWrite(LASER_PIN, LOW);
    Serial.println("Sent: Li-Fi communication successful!");
  }

  input = '\0'; // Reset input for next character
  delay(100); // Optional delay to avoid rapid transmissions
}