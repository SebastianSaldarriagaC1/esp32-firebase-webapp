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
#include "wifi/WifiManager.h"
#include "firebase/FirebaseManager.h"
#include "dht/DHTManager.h"

// Create the secrets.h file with the following content:
// #define WIFI_SSID "your-ssid"
// #define WIFI_PASSWORD "your-password
// #define API_KEY "your-api-key"
// #define DATABASE_URL "your-database-url"
#include "secrets.h"

WiFiManager wifiManager;
FirebaseManager firebaseManager;
DHTManager dhtManager(2); // GPIO pin 2

unsigned long sendDataPrevMillis = 0;

void setup()
{
  Serial.begin(115200);

  wifiManager.connectWiFi(WIFI_SSID, WIFI_PASSWORD);

  firebaseManager.initFirebase(API_KEY, DATABASE_URL);

  dhtManager.begin();
}

void loop()
{
  if (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0)
  {
    sendDataPrevMillis = millis();

    // Read temperature and humidity
    float temperature = dhtManager.readTemperature();
    float humidity = dhtManager.readHumidity();

    // Check if readings failed
    if (isnan(temperature) || isnan(humidity))
    {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

    // Send temperature and humidity data to Firebase
    firebaseManager.sendFloat("environment/temperature", temperature);
    firebaseManager.sendFloat("environment/humidity", humidity);
  }
}
