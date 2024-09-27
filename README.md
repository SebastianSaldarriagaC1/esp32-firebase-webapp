# IoT Project with ESP32 and Firebase: Temperature and Humidity Monitoring

This repository contains two projects that form a complete IoT solution for monitoring temperature and humidity using an ESP32 and a KY-015 (DHT11) sensor. The data is sent to Firebase for real-time storage, and a Firebase-based frontend is used for viewing the collected data.

## Repository Content

- **esp32-webapp/**: PlatformIO project for the ESP32 that collects sensor data and sends it to Firebase.
- **firebase-webapp/**: Firebase project acting as the frontend for real-time data visualization.

## Project Features

- **Microcontroller**: ESP32
- **Sensor**: KY-015 (DHT11 for temperature and humidity)
- **Cloud Platform**: Firebase (Real-time database)
- **Frontend**: Firebase app for real-time data visualization

## Objectives

- Apply IoT concepts using the ESP32 and Firebase.
- Collect temperature and humidity data from the environment.
- Send data to Firebase and store it in real-time.
- Demonstrate the complete IoT solution from sensor to cloud.

## Repository Structure

```
YourProject/
├── esp32-webapp/                   # PlatformIO project for the ESP32
│   ├── src/
│   │   ├── main.cpp                # Main file for the ESP32 project
│   │   ├── WiFiManager/
│   │   │   ├── WiFiManager.h       # Wi-Fi connection management
│   │   │   └── WiFiManager.cpp
│   │   ├── FirebaseManager/
│   │   │   ├── FirebaseManager.h   # Firebase connection management
│   │   │   └── FirebaseManager.cpp
│   │   ├── DHTManager/
│   │   │   ├── DHTManager.h        # Temperature and humidity sensor management
│   │   │   └── DHTManager.cpp
│   ├── include/
│   │   └── secrets.h               # Wi-Fi and Firebase credentials
│   ├── platformio.ini              # PlatformIO configuration file
├── firebase-webapp/                # Firebase project for the frontend
│   ├── public/
│   │   ├── index.html              # Main page for the frontend
│   │   ├── app.js                  # Main logic file for Firebase connection
│   │   └── styles.css              # CSS file to add styles to index.html
│   ├── firebase.json               # Firebase configuration
└── README.md                       # Project description file
```

## Installation and Setup

### Requirements

- **Hardware**: ESP32, KY-015 (DHT11) sensor
- **Software**: PlatformIO, Firebase account

### Step 1: Clone the Repository

```bash
git clone https://github.com/SebastianSaldarriagaC1/esp32-firebase-webapp.git
```

### Step 2: ESP32 Project Setup

1. Go to the `esp32-webapp/` folder.
2. Create the `include/secrets.h` file with your Wi-Fi and Firebase credentials:

```cpp
#define WIFI_SSID "your-ssid"
#define WIFI_PASSWORD "your-password"
#define API_KEY "your-api-key"
#define DATABASE_URL "https://your-database-url.firebaseio.com/"
```

3. Connect your ESP32 and upload the code

### Step 3: Firebase Project Setup

1. Go to the `firebase-webapp/` folder.
2. Make sure Firebase Hosting and the Realtime Database are configured.
3. Deploy the frontend to Firebase Hosting:

```bash
firebase deploy
```

## Project Functionality

1. **esp32-webapp**: The ESP32 collects temperature and humidity data using the KY-015 (DHT11) sensor and sends it to Firebase at regular intervals (15 seconds).
2. **firebase-webapp**: The data is stored in Firebase's real-time database and the frontend displays it.
