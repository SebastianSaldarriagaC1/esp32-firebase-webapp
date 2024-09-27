#include "FirebaseManager.h"
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"
#include <Arduino.h>

void FirebaseManager::initFirebase(const char *apiKey, const char *databaseUrl)
{
    config.api_key = apiKey;
    config.database_url = databaseUrl;

    // Sign up
    if (Firebase.signUp(&config, &auth, "", ""))
    {
        Serial.println("Firebase Sign-Up OK");
        signupOK = true;
    }
    else
    {
        Serial.printf("Sign-Up Error: %s\n", config.signer.signupError.message.c_str());
    }

    // Assign token status callback
    config.token_status_callback = tokenStatusCallback;

    // Start Firebase and reconnect to Wi-Fi if disconnected
    Firebase.begin(&config, &auth);
    Firebase.reconnectWiFi(true);
}

bool FirebaseManager::sendInt(const String &path, int value)
{
    if (Firebase.ready() && signupOK)
    {
        if (Firebase.RTDB.setInt(&fbdo, path, value))
        {
            Serial.println("PASSED");
            Serial.println("PATH: " + fbdo.dataPath());
            Serial.println("TYPE: " + fbdo.dataType());
            return true;
        }
        else
        {
            Serial.println("FAILED");
            Serial.println("REASON: " + fbdo.errorReason());
        }
    }
    return false;
}

bool FirebaseManager::sendFloat(const String &path, float value)
{
    if (Firebase.ready() && signupOK)
    {
        if (Firebase.RTDB.setFloat(&fbdo, path, value))
        {
            Serial.println("PASSED");
            Serial.println("PATH: " + fbdo.dataPath());
            Serial.println("TYPE: " + fbdo.dataType());
            return true;
        }
        else
        {
            Serial.println("FAILED");
            Serial.println("REASON: " + fbdo.errorReason());
        }
    }
    return false;
}
