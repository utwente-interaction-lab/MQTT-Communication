This file is meant to work in the arduinoIDE and to use the code a library is needed for the MQTT part.
The library that is needed is **EspMQTTClient** which can be found by going to **Sketch-> Include Library -> Manage Libraries...** in the arduinoIDE.

![alt text](https://github.com/utwente-interaction-lab/MQTT-Communication/blob/main/Images%20Tutorial/LocationLibraryManager.png)

The screen that now pops up (Library Manager) will show a search bar in here search for EspMQTTClient and now find it EspMQTTClient by Patrick Lapointe.
You can take the newest version, but when encountering difficulties with the example code the version used when writing the tutorial is 1.13.2.
To install just click the install button.


![alt text](https://github.com/utwente-interaction-lab/MQTT-Communication/blob/main/Images%20Tutorial/EspMQTTClient.png)

Below is the drawing of the example circuit and the diagram. This one is for the ep32 lolin32 board. 
If you use a different one it will look different but might also use different pins.
So before using check this. Make sure the middle pot pin supports analogue values.

![alt text](https://github.com/utwente-interaction-lab/MQTT-Communication/blob/main/Images%20Tutorial/SchemaLolin32.png)
![alt text](https://github.com/utwente-interaction-lab/MQTT-Communication/blob/main/Images%20Tutorial/DiagramLolin32.png)
