#include "DHTManager.h"
#include <Arduino.h>

DHTManager::DHTManager(int pin) : dht(pin, DHT11) {}

void DHTManager::begin()
{
    dht.begin();
}

float DHTManager::readTemperature()
{
    return dht.readTemperature();
}

float DHTManager::readHumidity()
{
    return dht.readHumidity();
}
