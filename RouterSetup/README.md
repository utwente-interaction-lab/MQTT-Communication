This part is an example of how to set a static ip in a router. This looks different for every router but the main princeples should be the same.
In this example the **TP-Link Wireless N Router WR841N**, this is a cheap router than van also be bought at the stores on campus.

First, make sure you are connected to the router otherwise you will not have acces to it. This can be done with a cable or WiFi. When you use WiFi the credentials for loging on should be on the underside if you or someone else did not change it.

To start find the ip of the interface portal of the router and the login credentails for that page. They should be on the bottom of the router.
In the example it is under Default Acces

![Login credentials](https://github.com/utwente-interaction-lab/MQTT-Communication/blob/main/Images%20Tutorial/underSideRouter.jpg)

Go that site and use the found credentails to login.
When logedin go to DHCP -> Addres Reservation. Here you can add a static IP for your devices.
You need to fill in a MAC Addres which for allready connected devices can be found under DHCP -> DHCP Client List.
And you have to choose an IP that is static, depending on the router you can do 192.186.1.xxx or 192.186.0.xxx. In this case it is 192.186.0.xxx.
To know what you need you can again look at the DHCP Client list and see what they got assigned there. 
When MAC and IP are filled in make sure it is enabled. To enforce the rules it can help to restart both the router and devices that got a static IP.

![DHCP Screen](https://github.com/utwente-interaction-lab/MQTT-Communication/blob/main/Images%20Tutorial/DHCPScreen.jpg)


