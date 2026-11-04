
#include <Servo.h>

// Servo motors
Servo servo1;
Servo servo2;

// Pin configuration
const int potPin1 = A0;
const int potPin2 = A1;
const int servoPin1 = 9;
const int servoPin2 = 10;

void setup() {
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  Serial.begin(9600);
}

void loop() {
  // Read potentiometer values
  int potValue1 = analogRead(potPin1);
  int potValue2 = analogRead(potPin2);

  // Convert readings to servo angles
  int angle1 = map(potValue1, 0, 1024, 0, 180);
  int angle2 = map(potValue2, 0, 1024, 0, 180);

  // Control the servo motors
  servo1.write(angle1);
  servo2.write(angle2);

  // Display angles in Serial Monitor
  Serial.print(angle1);
  Serial.print("\t");
  Serial.println(angle2);

  delay(50);
}
