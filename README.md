# MQTT Communication - overview
This tutorial is about setting up MQTT with an Espressif esp32. MQTT is a way for devices to send and receive messages to each other. The software that manages all this is called a broker. There will be an explanation and example code for all parts needed to setup up MQTT successfully. The parts needed and what will be explained are listed below in the order you need them;


- [Pi setup](https://github.com/utwente-interaction-lab/MQTT-Communication/tree/main/Pi%20Setup) (if you want to the MQTT broker on the pi)
	- Install operating system
		- Setup WiFi
		- Setup SSH

- [Router Setup](https://github.com/utwente-interaction-lab/MQTT-Communication/tree/main/Router%20Setup)
	- Static IP

- [MQTT broker setup](https://github.com/utwente-interaction-lab/MQTT-Communication/tree/main/MQTTBroker)
	- Windows
	- Raspberry pi /Debian based linux
 
 - [Code ESP32](https://github.com/utwente-interaction-lab/MQTT-Communication/tree/main/ESP32%20Code)
	 - Arduino

- [Code python](https://github.com/utwente-interaction-lab/MQTT-Communication/tree/main/Python%20Code)


# Key concepts


Within MQTT there are some key concepts that you need to understand to work with it

## Retention flag
A retention flag is something that can usually be turned on when publishing to a topic. When it is set to true the MQTT broker keeps track of the last published data to a topic. This means that when a device subscribes it will receive this data. Otherwise, it would only get data when the subscribing and publishing device is online at the same time. This is not always the case.

## QOS
QoS stands for Quality of service and can have three values. Not all values are supported by all devices/ code languages. For example, the library used for the esp32 does not support a QoS of 2. The three values are;
0: fire and forget. There is no check if the package actually arrives at the broker.
1: The device and broker check if the package is arrived by tracking all sent data on a topic with ID’s
2: The client will keep sending packages until an acknowledgement package is received.
The higher the number the less likely you are that a package is not received on the other end. 


## Publishing
Publishing is when a device shares data to the Broker and indirect the devices that want to receive the data. This is what you do with sensor data for example.

## Subscribing
Subscribing is when a device wants to receive certain data from a device. When a device is subscribed to a topic it will receive data every time a device publishes on that topic.


# How are devices connected

In the diagram below two devices are connected to the MQTT broker;
A laptop running a python program
An esp32 running code and reading a sensor

The Green arrows are the path being followed when a device wants to get data that arrives on a certain topic. The blue arrows are for the path data takes when the topic subscribed by the python program gets data. This can be more than one device. The purple arrows is the path taken when a device publishes data on a certain topic. As can be seen, all data has to go through the router and the MQTT broker. In the small example, the laptop running python subscribes to a certain topic. That topic is the topic where the esp32 publishes its data from the sensors. Now every time the esp32 publishes code to the topic, the broker sends the data to the connected laptop.


![network overview](https://github.com/utwente-interaction-lab/MQTT-Communication/blob/main/Images%20Tutorial/Diagram.svg)


 

# Example use cases

In general, the best use case for using MQTT is gathering data from remote sensors or control devices over the network.
The most basic examples are collecting temperature on a topic and having some python code put the values in a database on the machine that also hosts the MQTT broker.
However, MQTT can get more complicated by making an actual protocol. An example of this is an internet-enabled infrared remote to control things like the television with your phone like in [this](https://github.com/crankyoldgit/IRremoteESP8266/blob/master/examples/IRMQTTServer/IRMQTTServer.ino) example. 

But for simpler projects is can be useful to monitor or command devices from a distance. While otherwise, you would do this with the serial monitor in the Arduino IDE or processing.
