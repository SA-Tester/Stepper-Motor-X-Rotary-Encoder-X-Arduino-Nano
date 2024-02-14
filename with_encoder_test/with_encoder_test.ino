// Define the pins of the Stepper Motor Driver
const int stepPin = 3;
const int dirPin = 2;
const int enPin = 4;

// Define the pins of the rotary encoder
const int outA = 5;
const int outB = 6;

void setup() {
  // Configure input and output pins
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enPin, OUTPUT);
  pinMode(outA, INPUT);
  pinMode(outB, INPUT);

  // First disable the stepper motor
  digitalWrite(enPin, LOW);

  // Read the value of hte encoder
  int lastState = digitalRead(outA);
}

void loop() {
  // Repeatedly read the value of pin A
  int currentState = digitalRead(outA);

  if (lastState != currentState) {
    if (digitalRead(outB) != lastState) {
      digitalWrite(dirPin, HIGH);  // Enables the motor to move in a particular direction
      
      for (int x = 0; x < 800; x++) {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(500);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(500);
        delay(1000);  // One second delay
      }
    } else {
      digitalWrite(dirPin, LOW);  //Changes the direction of rotation

      for (int x = 0; x < 800; x++) {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(500);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(500);
      }
      delay(1000);
    }
  }
}
