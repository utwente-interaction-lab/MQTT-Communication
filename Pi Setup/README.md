# Setting up a Raspberry Pi

Here will be all things concerning setting up a pi to start using it.

## Installing an operating system

To install an operating system on a raspberry pi the easiest method is to use the [raspberry pi imager](https://www.raspberrypi.com/software/).
If you use a version with a GIU make sure you have a screen and keyboard. Otherwise, the use of a GUI is not possible and you might just choose a headless version.
A GUI is not recommended if you use the raspberry pi zero, 1 or 2. To choose a headless version in raspbian click on **Raspberry Pi OS (other)** and choose **Raspberry Pi OS Lite (32-bit)**. To make life easier so you will not need a keyboard and screen at all, some things can be configured after selecting the OS but **before** writing it to a **micro SD card**.

### SSH

To connect to the pi with your computer you can use SSH, you do need to be connected to the same network as the Pi otherwise it wont work. This also needs to be enabled on the pi. By default this is disabled but it can be enabled when making the image/operating system. This will be explained below.

### Hostname
Instead of an ip address you can also use a hostname. A hostname is basicly the same as using a website url like google. But this one only works with in your own little network. 
This makes some steps easier since you do not neccesarly need to give your pi a static IP anymore (still recommend it). And you also do not need to find the ip in your router anymore since you can fill in the hostname. For the example this will be **mqtt.local**.

Press **ctrl+shift+x** a secret menu will show up, in here do the following things:
- Fill in a hostname if you want to use that
- Enable SSH by checking the box
- Set a different password for the default "pi" user
- Configure WiFi. Check the box, fill in the credentials and set the Country to NL
- Set locale settings to the right time zone and keyboard layout
- Click save

<img src="https://github.com/utwente-interaction-lab/MQTT-Communication/blob/main/Images%20Tutorial/PiImagerChanges.png" width="600">

Now you can choose a storage device where the operating system needs to be flashed to. Makes sure it is a **micro SD card** since that is the only thing that fits in the raspberry pi and can hold the operating system. You can of course use adapters to connect the card to your computer.
Now press Write and wait till it is done, it will notify you.
Make sure the Pi is powered off, insert the micro SD card in its slot on the underside and power it on.
It may take some time but it should all work now

## Use SSH

To connect to the pi with your computer you can use SSH, you do need to be connected to the same network as the Pi otherwise it wont work.

Open the command prompt and type in ```ssh pi@192.168.x.xxx```. the x.xxx you have to find in the router settings and look for the IP address of the pi. If you filled in a hostname you can also use that. In the case of the example you would use ```ssh pi@mqtt.local```
If you have the right IP address it should ask if you trust it and want to save the fingerprint. Type ```yes```. Now type in the password you have chosen for the pi and you can send commands to the pi just like if you would open a terminal on the pi itself.
