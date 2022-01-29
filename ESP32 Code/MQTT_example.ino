/*This file is meant to work in the arduinoIDE and to use the code a library is needed for the MQTT part.
The library that is needed is EspMQTTClient which can be found by going to Sketch-> Include Library -> Manage Libraries... in the arduinoIDE.
The screen that now pops up (Library Manager) will show a search bar in here search for EspMQTTClient by Patrick Lapointe.
You can take the newest version, but when encountering difficulties with the example code the version used when writing the tutorial is 1.13.2.
*/

#include "EspMQTTClient.h"


long previousMillis = 0;  // variable to store previous running time
long interval = 5000; // how many milliseconds the function has to wait before running again


int LedPin = 19; // pin where the LED is connected to
String LedState = "off"; // in what state the LED will start without getting a message
int PotPin = 34; // pin where the Potentiometer value is read (middle pin)
int PotValue; // variable where the read potentiometer value is read


// values for connecting to the internet and mqtt broker/mosquitto
EspMQTTClient client(
  "ItechLab", // WiFi SSID/name
  "ItechLab", // WiFi password
  //"192.168.0.3",  // MQTT Broker server ip
  "mqtt.local", //if you use local host. uncomment the one you need. Both can work
  "ItechLab",   // MQTT/mosquitto user
  "ItechLab",   // MQTT/mosquitto password
  "ItechExample",     // Client name that uniquely identify your device. for example the website where the esp32 can be found for over the airupdate. default is ItechExample.local
  1883              // The MQTT port, default to 1883.
);

void setup() {
  // starts the serial communication with a baudrate of 115200
  Serial.begin(115200);
  //initializes the LED pin to output
  pinMode(LedPin, OUTPUT);
  //initializes the Pot pin to input/reading
  pinMode(PotPin, INPUT);
  //calls the function related to connecting to mqtt and internet
  ConnectToWiFi();


}


// functions that is called when connection is made
void onConnectionEstablished()
{

  //long currentMillis = millis();

  // Subscribes to ItechExample/LedControll", this toggles the led on and of from the example python code
  client.subscribe("ItechExample/LedControll", [](const String & payload) {
    Serial.println(payload); // prints the content of a message to the serial monitor
    LedState = payload; // Sets LedState to the received message
  });
}

void loop() {
  //loops the MQTT stuff do not use delay longer than 1ms in the code. since it will mess with this might break stuff
  client.loop();

  // gets the current runtime
  long currentMillis = millis();
  
  //if statement that tracks if x amount of seconds have passed since the last time
  if (currentMillis - previousMillis > interval) {
    
    // reads the value of the potentiometer
    PotValue = analogRead(PotPin);
    
    //prints that value to the serial monitor
    Serial.println(PotValue);

    //sends/publishes the data to the MQTT broker/mosquitto
    client.publish("ItechExample/ButtonPressed", String(PotValue), true); // You can activate the retain flag by setting the third parameter to true
   ;
   // resets the timer that tracks how much time has passed
    previousMillis = currentMillis; // reset the variable currentMillis to current run time.
  }

  // toggles the LED based on the received message
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

// function related to network connections (MQTT/WiFi)
void ConnectToWiFi()
{


  client.enableDebuggingMessages(); // Enable debugging messages sent to serial output
  client.enableHTTPWebUpdater(); // Enable the web updater. User and password default to values of MQTTUsername and MQTTPassword. These can be overridded with enableHTTPWebUpdater("user", "password").
  client.enableOTA(); // Enable OTA (Over The Air) updates. Password defaults to MQTTPassword. Port is the default OTA port. Can be overridden with enableOTA("password", port).
  client.enableLastWillMessage("TestClient/lastwill", "I am going offline");  // You can activate the retain flag by setting the third parameter to true
  Serial.println(WiFi.macAddress());
}
