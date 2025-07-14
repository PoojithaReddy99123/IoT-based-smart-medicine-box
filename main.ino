#include <Servo.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

// Replace with your WiFi credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

// IFTTT Webhook details
const char* host = "maker.ifttt.com";
const int httpsPort = 443;
const char* trigger = "missed_medicine"; // Your IFTTT event name
const char* key = "YOUR_IFTTT_KEY";      // Your IFTTT webhook key

Servo medicineServo;
const int buzzerPin = D1;
const int irSensorPin = D2;
const int servoPin = D3;

void setup() {
  Serial.begin(115200);
  pinMode(buzzerPin, OUTPUT);
  pinMode(irSensorPin, INPUT);
  medicineServo.attach(servoPin);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected!");

  delay(2000); // wait before first alert
  alertUser();
}

void loop() {
  // Nothing to do in loop
}

void alertUser() {
  digitalWrite(buzzerPin, HIGH);
  delay(3000); // Buzz for 3 sec
  digitalWrite(buzzerPin, LOW);

  openMedicineBox();

  bool taken = checkIfMedicineTaken();
  if (!taken) {
    sendNotification();
  }

  closeMedicineBox();
}

void openMedicineBox() {
  medicineServo.write(90); // Open
  delay(1000);
}

void closeMedicineBox() {
  medicineServo.write(0); // Close
  delay(1000);
}

bool checkIfMedicineTaken() {
  Serial.println("Waiting for medicine pickup...");
  int timeLimit = 10000; // 10 seconds to pick medicine
  int elapsed = 0;
  while (elapsed < timeLimit) {
    if (digitalRead(irSensorPin) == LOW) { // LOW = object detected
      Serial.println("Medicine taken.");
      return true;
    }
    delay(500);
    elapsed += 500;
  }
  Serial.println("Medicine NOT taken.");
  return false;
}

void sendNotification() {
  WiFiClientSecure client;
  client.setInsecure(); // skip SSL certificate validation

  Serial.println("Connecting to IFTTT...");
  if (!client.connect(host, httpsPort)) {
    Serial.println("Connection failed.");
    return;
  }

  String url = String("/trigger/") + trigger + "/with/key/" + key;
  Serial.print("Requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");

  Serial.println("Notification sent.");
}
