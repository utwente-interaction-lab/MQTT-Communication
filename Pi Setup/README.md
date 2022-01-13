# Setting up a Raspberry Pi

Here will all things concerning setting up a pi to start using it.

## Installing an operating system

To install a operating system on a raspberry pi the easiest method is to use the [raspberry pi imager](https://www.raspberrypi.com/software/).
If you use a version with a GIU make sure you have a screen and keyboard. Otherwise the use of a GUI is not possible and you might just chose a headless version.
A GUI is not recommened if you use the rasperry pi zero, 1 or 2. To choose a headless version in raspbian click on **Raspberry Pi OS (other)** and choose **Raspberry Pi OS Lite (32-bit)**. To make life easier so you wont need a keyboard and screen at all some things can be configured after selecting the OS but before writing it to an **micro SD card**.

Press **ctrl+shift+x** a secret menu will show in here:
- Enable SSH by checking the box
- Set a different password for the default "pi" user
- Configure WiFi. Check the box and fill in the credentials and set the Country to NL
- Set locale settings to the right time zone and keyboard layout
- Click save

<img src="https://github.com/utwente-interaction-lab/MQTT-Communication/blob/main/Images%20Tutorial/PiImagerChanges.png" width="600">

Now you can choose a storage device where the operating system needs to be flashed to. Makes sure it is an **micro SD card** since that is the only thing that fits in the raspberry pi and can hold the operating system. You can offcourse use adapters to connect the card to your computer.
Now press Write and wait till it is done, it will notify you.
Make sure the Pi is powered off, put in the micro SD card in its slot on the underside and power it on.
It may take some time but it should all work now.

## SSH

To connect to the pi with your computer you can use SSH, you do need to be connected to the same network as the Pi otherwise it wont work.

Open an the command prompt and type in ```ssh pi@192.186.x.xxx``` the x.xxx you have to find in the router settings and look for the ip of the pi.
If you have the right ip it should ask if you trust it and want to save the fingerprint. Choose yes. Now type in the password you have choosen for the pi and you can send commands to the pi just like if you would open a terminal on the pi itself.
