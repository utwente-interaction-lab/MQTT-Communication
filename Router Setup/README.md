This part is an example of how to set a static IP in a router. This looks different for every router but the main principles should be the same.
In this example the router is a **TP-Link Wireless N Router WR841N**, this is a cheap router that can be bought at the stores on campus.

First, make sure you are connected to the router otherwise you will not have access to it. This can be done with a cable or via WiFi. When you use WiFi the credentials for connecting should be on the underside, if you or someone else did not change it.

To start, find the IP of the interface portal of the router and the login credentials for that page. They should be on the bottom of the router.
In the example, it is under Default Acces.


<img src="https://github.com/utwente-interaction-lab/MQTT-Communication/blob/main/Images%20Tutorial/underSideRouter.jpg" width="300">

Go to that site and use the found credentials to log in.
When logged in go to **DHCP -> Address Reservation**. Here you can add a static IP for your devices.
You need to fill in a MAC Address which for already connected devices can be found under **DHCP -> DHCP Client List**.
And you have to choose a static IP for the device, depending on the router it usually is **192.168.1.xxx or 192.168.0.xxx** but could be anything. In this case, it is 192.168.0.xxx.
To know what you need you can again look at the DHCP Client list and see what they got assigned there. But if the portal shows an IP in the browser URL field, you can see it there since it uses the same. When MAC and IP are filled in make sure it is enabled. To make sure the static IP is used, it can help to restart both the router and devices that got a static IP.




![DHCP Screen](https://github.com/utwente-interaction-lab/MQTT-Communication/blob/main/Images%20Tutorial/DHCPScreen.jpg)


