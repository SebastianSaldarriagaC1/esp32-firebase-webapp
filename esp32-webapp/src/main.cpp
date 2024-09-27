/*
  Rui Santos
  Complete project details at our blog.
    - ESP32: https://RandomNerdTutorials.com/esp32-firebase-realtime-database/
    - ESP8266: https://RandomNerdTutorials.com/esp8266-nodemcu-firebase-realtime-database/
  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files.
  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
  Based in the RTDB Basic Example by Firebase-ESP-Client library by mobizt
  https://github.com/mobizt/Firebase-ESP-Client/blob/main/examples/RTDB/Basic/Basic.ino
*/

#include <Arduino.h>
// Remember to update include path in platformio.ini
#include "wifi/WifiManager.h"
#include "firebase/FirebaseManager.h"

// Create the secrets.h file with the following content:
// #define WIFI_SSID "your-ssid"
// #define WIFI_PASSWORD "your-password
// #define API_KEY "your-api-key"
// #define DATABASE_URL "your-database-url"
#include "secrets.h"

// Create WiFi and Firebase manager objects
WiFiManager wifiManager;
FirebaseManager firebaseManager;

unsigned long sendDataPrevMillis = 0;
int count = 0;

void setup()
{
  // Start Serial Monitor
  Serial.begin(115200);

  // Connect to Wi-Fi
  wifiManager.connectWiFi(WIFI_SSID, WIFI_PASSWORD);

  // Initialize Firebase
  firebaseManager.initFirebase(API_KEY, DATABASE_URL);
}

void loop()
{
  if (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0)
  {
    sendDataPrevMillis = millis();

    // Send integer value to Firebase
    firebaseManager.sendInt("web/int", count);
    count++;

    // Send float value to Firebase
    firebaseManager.sendFloat("web/float", 0.01 + random(0, 100));
  }
}