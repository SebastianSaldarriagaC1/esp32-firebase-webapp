#ifndef DHTMANAGER_H
#define DHTMANAGER_H

#include <DHT.h>

class DHTManager
{
public:
    DHTManager(int pin);
    void begin();
    float readTemperature();
    float readHumidity();

private:
    DHT dht;
};

#endif // DHTMANAGER_H
