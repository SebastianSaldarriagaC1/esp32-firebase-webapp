#ifndef FIREBASEMANAGER_H
#define FIREBASEMANAGER_H

#include <Firebase_ESP_Client.h>

class FirebaseManager
{
public:
    void initFirebase(const char *apiKey, const char *databaseUrl);
    bool sendInt(const String &path, int value);
    bool sendFloat(const String &path, float value);

private:
    FirebaseData fbdo;
    FirebaseAuth auth;
    FirebaseConfig config;
    bool signupOK = false;
};

#endif // FIREBASEMANAGER_H
