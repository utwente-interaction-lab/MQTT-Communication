This file is meant to work in the arduinoIDE and to use the code a library is needed for the MQTT part. The library that is needed is **EspMQTTClient** which can be found by going to **Sketch -> Include Library -> Manage Libraries…** in the arduinoIDE. The example is made for the **lolin32 esp32 board**. Make sure to check if pins are used to same when using a different board like the Adafruit Feather.

![alt text](https://github.com/utwente-interaction-lab/MQTT-Communication/blob/main/Images%20Tutorial/LocationLibraryManager.png)

The screen that now pops up (Library Manager) will show a search bar in here search for EspMQTTClient and now find it EspMQTTClient by Patrick Lapointe. You can take the newest version, but when encountering difficulties with the example code, the version used when writing the tutorial is 1.13.2. To install the library just click the install button.

When using the code Arduino expects it to be in a folder with the same name as the file. The ArduinoIDE should ask if you want it to be put in a folder. But if things don’t want to start you can try this.

![alt text](https://github.com/utwente-interaction-lab/MQTT-Communication/blob/main/Images%20Tutorial/EspMQTTClient.png)

Below is the drawing of the example circuit and the diagram. This one is for the **esp32 lolin32** board. 
If you use a different one like the adafruit feather, it will look different but might also use different pins.
So before using check this. Make sure the middle pot pin supports analogue values.

![alt text](https://github.com/utwente-interaction-lab/MQTT-Communication/blob/main/Images%20Tutorial/SchemaLolin32.png)
![alt text](https://github.com/utwente-interaction-lab/MQTT-Communication/blob/main/Images%20Tutorial/DiagramLolin32.png)
