#include <Wire.h>
#include "RTClib.h"

const int buzzerPin = 8;
const int irSensorPin = 9;
const int motorPin1 = 6; // for L293D IN1
const int motorPin2 = 7; // for L293D IN2

RTC_DS3231 rtc;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(irSensorPin, INPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // Uncomment once to set RTC time
}

void loop() {
  DateTime now = rtc.now();

  // Set alert time (e.g., 9:00 AM)
  if (now.hour() == 9 && now.minute() == 0 && now.second() == 0) {
    alertUser();
    delay(1000); // Wait 1 second to avoid multiple triggers
  }

  delay(500);
}

void alertUser() {
  // Buzzer alert
  digitalWrite(buzzerPin, HIGH);
  delay(3000);
  digitalWrite(buzzerPin, LOW);

  // Open tray
  openTray();

  bool picked = checkIfPicked();

  if (!picked) {
    Serial.println("Medicine not picked.");
  } else {
    Serial.println("Medicine picked.");
  }

  // Close tray after wait
  delay(2000);
  closeTray();
}

void openTray() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  delay(2000); // Adjust motor duration to open fully
  stopMotor();
}

void closeTray() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  delay(2000); // Adjust motor duration to close fully
  stopMotor();
}

void stopMotor() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
}

bool checkIfPicked() {
  int timeout = 10000;
  int elapsed = 0;
  while (elapsed < timeout) {
    if (digitalRead(irSensorPin) == LOW) {
      return true;
    }
    delay(500);
    elapsed += 500;
  }
  return false;
}