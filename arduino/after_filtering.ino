
#include <Servo.h>

// Servo motor declarations
Servo servo1;
Servo servo2;

// Pin configuration
const int potPin1 = A0;
const int potPin2 = A1;
const int servoPin1 = 9;
const int servoPin2 = 10;

// First-order digital low-pass filter
float alpha = 0.1;
float filteredPot1 = 0;
float filteredPot2 = 0;

void setup() {
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);

  Serial.begin(9600);
}

void loop() {
  // Read potentiometer values
  int potValue1 = analogRead(potPin1);
  int potValue2 = analogRead(potPin2);

  // Apply the first-order low-pass filter
  filteredPot1 = alpha * potValue1
               + (1 - alpha) * filteredPot1;

  filteredPot2 = alpha * potValue2
               + (1 - alpha) * filteredPot2;

  // Convert filtered values to servo angles
  int angle1 = map(filteredPot1, 0, 1023, 0, 180);
  int angle2 = map(filteredPot2, 0, 1023, 0, 180);

  // Control the servo motors
  servo1.write(angle1);
  servo2.write(angle2);

  // Display angles in Serial Monitor
  Serial.print(angle1);
  Serial.print("\t");
  Serial.println(angle2);

  delay(50);
}
