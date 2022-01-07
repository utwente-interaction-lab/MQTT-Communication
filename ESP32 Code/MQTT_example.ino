/*This file is meant to work in the arduinoIDE and to use the code a library is needed for the MQTT part.
The library that is needed is EspMQTTClient which can be found by going to Sketch-> Include Library -> Manage Libraries... in the arduinoIDE.
The screen that now pops up (Library Manager) will show a search bar in here search for EspMQTTClient by Patrick Lapointe.
You can take the newest version, but when encountering difficulties with the example code the version used when writing the tutorial is 1.13.2.
*/

#include "EspMQTTClient.h"

long previousMillis = 0;  // variable to store previous running time
long interval = 1000; // how many milliseconds the function has to wait before running again

int LedPin = 19;
String LedState = "off";
int PotPin = 34;
int PotValue;


EspMQTTClient client(
  "ItechLab",
  "ItechLab",
  "192.168.0.101",  // MQTT Broker server ip
  "ItechLab",   // Can be omitted if not needed
  "ItechLab",   // Can be omitted if not needed
  "ItechExample",     // Client name that uniquely identify your device
  1883              // The MQTT port, default to 1883. this line can be omitted
);

void setup() {
  Serial.begin(115200);
  pinMode(LedPin, OUTPUT);
  pinMode(PotPin, INPUT);
}



void onConnectionEstablished()
{

  long currentMillis = millis();

  // Subscribe to "mytopic/test" and display received message to Serial
  client.subscribe("ItechExample/LedControll", [](const String & payload) {
    Serial.println(payload);
    LedState = payload;
  });
}

void loop() {
  client.loop();
  long currentMillis = millis();
  if (currentMillis - previousMillis > interval) {
    // Publish a message to "mytopic/test"
    PotValue = analogRead(PotPin);
    Serial.println(PotValue);
    client.publish("ItechExample/ButtonPressed", String(PotValue), true); // You can activate the retain flag by setting the third parameter to true
    //Serial.println("test");
    previousMillis = currentMillis; // reset the variable currentMillis to current run time.
  }

  if (LedState == "on") {
    digitalWrite(LedPin, LOW);
    Serial.println("LED turned on");
    LedState = "changed";
  }
  else if (LedState == "off") {
    digitalWrite(LedPin, HIGH);
    Serial.println("LED turned off");
    LedState = "changed";
  }

}
