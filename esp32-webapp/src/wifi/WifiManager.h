#ifndef WIFIMANAGER_H
#define WIFIMANAGER_H

#include <WiFi.h>

class WiFiManager
{
public:
    void connectWiFi(const char *ssid, const char *password);
};

#endif // WIFIMANAGER_H
