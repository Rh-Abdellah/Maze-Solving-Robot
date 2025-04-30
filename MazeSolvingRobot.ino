#include <AFMotor.h>

// Motor setup
AF_DCMotor motorLeft(1);
AF_DCMotor motorRight(2);

// Ultrasonic sensor pins
const int trigFront = 7, echoFront = 6;
const int trigLeft = 9, echoLeft = 8;
const int trigRight = 11, echoRight = 10;

// PID variables
float kp = 2.0, ki = 0.0, kd = 1.0;
float error = 0, prevError = 0, integral = 0;

// Read distance from an ultrasonic sensor
long readDistance(int trig, int echo) {
  digitalWrite(trig, LOW); delayMicroseconds(2);
  digitalWrite(trig, HIGH); delayMicroseconds(10);
  digitalWrite(trig, LOW);
  return pulseIn(echo, HIGH) * 0.034 / 2;
}

// Adjust motor speed using PID
void applyPID(float error) {
  integral += error;
  float derivative = error - prevError;
  float correction = kp * error + ki * integral + kd * derivative;
  prevError = error;

  int baseSpeed = 150;
  int speedLeft = constrain(baseSpeed - correction, 100, 255);
  int speedRight = constrain(baseSpeed + correction, 100, 255);

  motorLeft.setSpeed(speedLeft);
  motorRight.setSpeed(speedRight);
}

void setup() {
  Serial.begin(9600);
  pinMode(trigFront, OUTPUT); pinMode(echoFront, INPUT);
  pinMode(trigLeft, OUTPUT); pinMode(echoLeft, INPUT);
  pinMode(trigRight, OUTPUT); pinMode(echoRight, INPUT);
  motorLeft.run(FORWARD);
  motorRight.run(FORWARD);
}

void loop() {
  long distFront = readDistance(trigFront, echoFront);
  long distLeft = readDistance(trigLeft, echoLeft);
  long distRight = readDistance(trigRight, echoRight);

  if (distFront < 20) {
    // Obstacle ahead
    if (distLeft > distRight) {
      motorLeft.run(BACKWARD); motorRight.run(FORWARD); delay(400);
    } else {
      motorLeft.run(FORWARD); motorRight.run(BACKWARD); delay(400);
    }
  } else {
    // Move forward with PID correction
    error = distLeft - distRight;
    applyPID(error);
    motorLeft.run(FORWARD);
    motorRight.run(FORWARD);
  }

  delay(100);
}
