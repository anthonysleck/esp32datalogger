/*
   ESP32 Data Logger
   Description:
   Using an ESP32 to monitor and log data of a tool
   Notes:

   Changelog:
   0.1 - new code
*/

#ifndef config_h
#define config_h

// system versioning
#define VER "0.1"
#define VER_BUILD "05102023"

// includes
#include <Arduino.h>
#include <AsyncElegantOTA.h>
#include <ESPAsyncWebServer.h>
#include <HTTPClient.h>
#include "webpages.h"
#include <WiFi.h>
#include <WiFiClient.h>

// debugging
#define DEBUG 1     // set to "0" to disable serial debugging

#if DEBUG == 1
#define debug(x) Serial.print(x)
#define debugln(x) Serial.println(x)
#else
#define debug(x)
#define debugln(x)
#endif

// server configs
AsyncWebServer server(80);

// wd timer
#define WATCHDOG_TIMEOUT_S 15            // enter time in sec
hw_timer_t *watchDogTimer = NULL;

// WiFi settings
const char *ssid = "DataLog";             // enter your SSID here
const char *password = "12345678"; // enter password here

#endif