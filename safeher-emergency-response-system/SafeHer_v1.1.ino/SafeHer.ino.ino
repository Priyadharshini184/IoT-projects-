#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <TinyGPS++.h>
#include <Preferences.h>

#define SOS_BUTTON 33

// ================= WIFI =================
const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";

// =============== TELEGRAM ===============
String BOT_TOKEN = "YOUR_BOT_TOKEN";
String CHAT_ID   = "YOUR_CHAT_ID";

// ================= CONTACTS =================
String CONTACT1 = "YOUR_PHONE_NUMBER1"; // Parent
String CONTACT2 = "YOUR_PHONE_NUMBER2"; // Guardian
String CONTACT3 = "YOUR_PHONE_NUMBER3"; // Friend

// ================= GPS =================
TinyGPSPlus gps;
HardwareSerial GPSSerial(1);

// ================= SIM800L =================
HardwareSerial sim800(2);
Preferences prefs;
bool alertSent = false;

float lastLat = 0;
float lastLon = 0;
bool locationStored = false;

// ===================================================
// SEND TELEGRAM ALERT
// ===================================================
void sendTelegram(float lat, float lon)
{
  WiFiClientSecure client;
  client.setInsecure();

  HTTPClient http;

  String message =
  "SAFEHER EMERGENCY ALERT\n\n"
  "A distress signal has been triggered.\n\n"
  "Latitude: " + String(lat,6) +
  "\nLongitude: " + String(lon,6) +
  "\n\nGoogle Maps:\nhttps://maps.google.com/?q=" +
  String(lat,6) + "," + String(lon,6) +
  "\n\nPlease contact the user immediately.";

  String url =
    "https://api.telegram.org/bot" +
    BOT_TOKEN +
    "/sendMessage";

  http.begin(client, url);

  http.addHeader(
    "Content-Type",
    "application/x-www-form-urlencoded"
  );

  String postData =
    "chat_id=" + CHAT_ID +
    "&text=" + message;

  int httpCode = http.POST(postData);

  Serial.print("Telegram HTTP Code: ");
  Serial.println(httpCode);

  Serial.println(http.getString());

  http.end();
}

// ===================================================
// SEND SMS ALERT
// ===================================================
void sendSMS(String number, float lat, float lon)
{
  String sms =
  "SAFEHER ALERT\n"
  "Emergency assistance requested.\n\n"
  "Location:\nhttps://maps.google.com/?q=" +
  String(lat,6) + "," + String(lon,6);

  sim800.println("AT+CMGF=1");
  delay(1000);

  sim800.print("AT+CMGS=\"");
  sim800.print(number);
  sim800.println("\"");

  delay(1000);

  sim800.print(sms);

  delay(500);

  sim800.write(26);

  delay(5000);

  Serial.print("SMS Sent To: ");
  Serial.println(number);
}


void setup()
{
  Serial.begin(115200);

  pinMode(SOS_BUTTON, INPUT_PULLUP);

  // GPS
  GPSSerial.begin(9600, SERIAL_8N1, 16, 17);

  // SIM800L
  sim800.begin(9600, SERIAL_8N1, 26, 27);

  Serial.println("================================");
  Serial.println("SAFEHER v1.1");
  Serial.println("System Starting...");
  Serial.println("================================");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  prefs.begin("safeher", false);

lastLat = prefs.getFloat("lat", 0);
lastLon = prefs.getFloat("lon", 0);

if(lastLat != 0 && lastLon != 0)
{
  locationStored = true;

  Serial.println("Stored Location Loaded");

  Serial.print("Latitude: ");
  Serial.println(lastLat, 6);

  Serial.print("Longitude: ");
  Serial.println(lastLon, 6);
}
  Serial.println("\nWiFi Connected");
  Serial.println("System Ready");
}

void loop()
{
  // Read GPS data continuously
  while (GPSSerial.available())
  {
    gps.encode(GPSSerial.read());
  }

  // Save last known location
  if (gps.location.isUpdated())
{
  lastLat = gps.location.lat();
  lastLon = gps.location.lng();

  locationStored = true;

  prefs.putFloat("lat", lastLat);
  prefs.putFloat("lon", lastLon);
}

  // SOS Button Pressed
  if (digitalRead(SOS_BUTTON) == LOW && !alertSent)
  {
    Serial.println("\nSOS BUTTON PRESSED");
    Serial.println("Hold for 3 seconds...");

    delay(3000);

    if (digitalRead(SOS_BUTTON) == LOW)
    {
      float lat;
      float lon;

      if (gps.location.isValid())
      {
        lat = gps.location.lat();
        lon = gps.location.lng();

        Serial.println("Using Current GPS Location");
      }
      else if (locationStored)
      {
        lat = lastLat;
        lon = lastLon;

        Serial.println("GPS Unavailable");
Serial.println("Using Stored Emergency Location");
      }
      else
      {
        Serial.println("No GPS Data Available");
        return;
      }

      Serial.print("Latitude: ");
      Serial.println(lat, 6);

      Serial.print("Longitude: ");
      Serial.println(lon, 6);

      Serial.println("Sending Telegram...");
      sendTelegram(lat, lon);

      Serial.println("Sending SMS To Parent...");
      sendSMS(CONTACT1, lat, lon);

      Serial.println("Sending SMS To Guardian...");
      sendSMS(CONTACT2, lat, lon);

      Serial.println("Sending SMS To Friend...");
      sendSMS(CONTACT3, lat, lon);

      Serial.println("================================");
      Serial.println("ALERT COMPLETED SUCCESSFULLY");
      Serial.println("================================");

      alertSent = true;
    }
    else
    {
      Serial.println("Alert Cancelled");
    }
  }

  // Reset alert state when button released
  if (digitalRead(SOS_BUTTON) == HIGH)
  {
    alertSent = false;
  }
}
