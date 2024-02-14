// Define the pins of the Stepper Motor Driver
const int stepPin = 3;
const int dirPin = 2;
const int enPin = 4;

void setup() {
  // Configure input and output pins
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enPin, OUTPUT);

  // First disable the stepper motor
  digitalWrite(enPin, LOW);
}

void loop() {
  // Set the direction pin to HIGH (clockwise)
  digitalWrite(dirPin, HIGH);

  // Turn the motor shaft by 800 steps (around 90 degrees)
  for (int x = 0; x < 800; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);

    // Wait 1 second
    delay(1000);  
  }

  // Set hte direction pin to LOW (anticlokwise)
  digitalWrite(dirPin, LOW);

  // Turn the motor shaft by 800 steps (around 90 degrees)
  for (int x = 0; x < 800; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  //Wait 1 second
  delay(1000);
}