// includes

#include "config.h"

void IRAM_ATTR watchDogInterrupt()
{
  debugln("reboot");
  ESP.restart();
}

void watchDogRefresh()
{
  timerWrite(watchDogTimer, 0);   //reset timer
}

void startWatchdogTimer()
{
  debugln("Starting watchdog timer!");
  watchDogTimer = timerBegin(2, 80, true);
  timerAttachInterrupt(watchDogTimer, &watchDogInterrupt, true);
  timerAlarmWrite(watchDogTimer, WATCHDOG_TIMEOUT_S * 1000000, false);
  timerAlarmEnable(watchDogTimer);
  debugln("Watchdog timer started!");
}

void rootServer()
{
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/html", index_html); });

  // start ElegantOTA
  AsyncElegantOTA.begin(&server);
  server.begin();
  debugln("HTTP server started");
}

void setup()
{
  delay(5000);

  // start serial
  Serial.begin(115200);

  // print sketch information
  debug("Version ");
  debugln(VER);
  debug("Build Code ");
  debugln(VER_BUILD);

  // start WiFi
  debugln();
  debugln();
  debug("Starting WIFI AP with SSID of ");
  debugln(ssid);
  WiFi.softAP(ssid, password);
  
  IPAddress IP = WiFi.softAPIP();
  debug("AP IP address: ");
  debugln(IP);

  // start server
  rootServer();

  // start watchdog timer
  startWatchdogTimer();
}

void loop()
{
  // reset watchdog timer
  watchDogRefresh();
}