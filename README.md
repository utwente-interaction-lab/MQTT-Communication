# MQTT Communication
This tutorial is about setting up MQTT with a Espressif esp32. 
There will be an explanation and example code for all parts needed to setup up MQTT successfully.

The parts needed and what will be explained will be as follows;

 - Code ESP32
	 - Arduino
	 - micropython

- Code python


- MQTT broker setup
	- Windows
	- Raspberry pi /Debian based linux
		- ssh

- Network routing


# MQTT Broker setup

Here will be explained how to set up the MQTT broker for various devices.
The MQTT broker is the programme that handles all the communication between devices.
It enables the ability for devices to subscribe or publish to topics and have it all work.
This guide is based on the guide on http://www.steves-internet-guide.com


## Install MQTT pi/Debian based linux

First, make sure the device has access to the internet. Having access to the internet is not the same as having a connection with the router.
The router needs to be able to access the internet.
When you have access to the internet start with making sure the device is up to date. This can be done with the following two commands;
- ```sudo apt update```
- ```sudo apt upgrade```

When everything is up to date you have to install the mosquitto broker which can be done with the following command
- ```sudo apt install mosquitto mosquitto-clients```

At the moment you have setup the MQTT client to know what IP it has on the network the following command can be used;
-```sudo ifconfig```
The IP is most likely something like 192.168.x.xxx

However know everyone that can connect to your little network has access to the data being send, this is why the next step is to make it password protected.
To have an easy overview of messages being send on your broker you can use a tool like [MQTT explorer](http://mqtt-explorer.com/).

### Setup password MQTT pi/Debian

start with the command ```sudo mosquitto_passwd -c /etc/mosquitto/credentials ItechLab``` where ItechLab is the username and credentails the name of the file users will be stored in. This can be whatever you want it to be.
When this command has been entered you are being promt to enter a password twice. Make sure it is somewhat secure and you remember it.

At the moment there still is no need to enter a username and password to connect to the broker, there only has been a user created.
This is why there are some changes needed in the MQTT config file. Start with ```sudo nano /etc/mosquitto/mosquitto.conf```. Nano is the editor that works in commandline, part after that is the location of the file.
Now the file opens and add the botom add the following two lines;
- ```allow_anonymous false```
- ```password_file /etc/mosquitto/credentials```
If you choose a different name for the file passwords are stored in or location. The "```/etc/mosquitto/credentials```" will be something else.
 When the lines have been added close the editor with ```ctrl x``` and press ```y``` to confirm. 
 To enforce the new rules in the config  type ```sudo service mosquitto restart``` in the command prompt.
 
 ## Setup MQTT on Windows 10
 Start with downloading the MQTT.exe from [here](https://mosquitto.org/download/) and grab the mosquitto-x.x.x-install-windows-x64.exe file under Windows.
 When downloaded dubbel click the file to start installing it, and just go through the installer.
 
 When the installer has been completed open your command prompt as an adminstrator.
 - running programms as an adminstrator can be done by searching for it in windows search and rightclicking it.

![alt text](https://github.com/utwente-interaction-lab/MQTT-Communication/blob/main/Images%20Tutorial/Adminstrator.png)

Now type in ``sc start mosquitto`` and it should start. It will start automatically when your computer turns on from now on.
Now type in ``sc query mosquitto`` to check if it is running it should look something like this;

![alt text](https://github.com/utwente-interaction-lab/MQTT-Communication/blob/main/Images%20Tutorial/MosquittoCheck.png)

Now edit the config file of mosquitto to ensure it can be found by devices that are not the computer/laptop itself.
Start with opening notepad or other text editor as administator the same way as done with the commandprompt.
Go to File->Open... and locate the config file. It should be in ``C:\Program Files\mosquitto`` and the file is called mosquitto.conf. Make sure you select all files so notepad can not only see .txt files
Now add at the top the following two line;
- ``listener 1883 0.0.0.0``
- ``allow_anonymous true``
Now use ``ctrl s`` t0 save it

The second line will be changed later to make it more secure.
Now the following steps in the commandpromtp that should still be open as administator.;

- ``sc stop mosquitto`` 
- ``cd C:\Program Files\mosquitto``  (This is if the default installation location has been used for mosquitto.)
- ``mosquitto -c mosquitto.conf``

A prompt should now pop-up asking for network permissions. 
![alt text](https://github.com/utwente-interaction-lab/MQTT-Communication/blob/main/Images%20Tutorial/MosquittoNetworkPrompt.png)

click on allow acces so devices can find the MQTT broker.
To have an easy overview of messages being send on your broker you can use a tool like [MQTT explorer](http://mqtt-explorer.com/).

### Setup password MQTT Windows 10 
Begin again with opening de command prompt again as adminstrator (not needed if still open) and use the following two commands.
Again go to the mosquitto folder with ``cd C:\Program Files\mosquitto`` and now type make a user and a credentails file, the file will be called **credentails** and the user **itechlab** ``mosquitto_passwd -c credentials itechlab``. You will be asked to type in a password twice, make sure you remember it since it will be needed to connect to the broker in the future.
 
 Now type in ``sc stop mosquitto`` to stop mosquitto so the config file can be edited. To do this open notepad as adminstrator and go to file->open... and go to ``c:\program files\mosquitto``. Make sure you have selected to see all files and open the mosquitto.conf file.
 In the file change the line **allow_anonymous true** to **allow_anonymous false**. Save with ``ctrl s``.
 Not type ``sc start mosquitto`` in the command prompt and it should work now.
 






 

