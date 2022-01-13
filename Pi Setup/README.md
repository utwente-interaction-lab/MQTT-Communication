To install a operating system on a raspberry pi the easiest method is to use the [raspberry pi imager](https://www.raspberrypi.com/software/).
If you use a version with a GIU make sure you have a screen and keyboard. Otherwise the use of a GUI is not possible and you might just chose a headless version.
A GUI is not recommened if you use the rasperry pi zero, 1 or 2. To choose a headless version in raspbian click on **Raspberry Pi OS (other)** and choose **Raspberry Pi OS Lite (32-bit)**. To make life easier so you wont need a keyboard and screen at all some things can be configured after selecting the OS but before writing it to an SD card.

Press **ctrl+shift+x** a secret menu will show in here:
- Enable SSH by checking the box
- Set a different password for the default "pi" user
- Configure WiFi. Check the box and fill in the credentials and set the Country to NL
- Set locale settings to the right time zone and keyboard layout

<img src="https://github.com/utwente-interaction-lab/MQTT-Communication/blob/main/Images%20Tutorial/PiImagerChanges.png" width="600">

