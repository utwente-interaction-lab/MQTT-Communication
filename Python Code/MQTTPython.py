

import paho.mqtt.client as mqtt
from time import time

MQTT_HOST = "192.168.1.118"
MQTT_USER = "mcpijnappel"
MQTT_PASSWORD = "Vs@ZDH%w2%0R1IaM"



def on_connect(client, userdata,flags,rc):
    print("Connected with result code "+str(rc))
    client.subscribe("ItechExample/ButtonPressed")
    
def on_message(client, userdata, msg):
    print(msg.topic+" "+str(msg.payload))
    

def my_connect():
    Time = time()
    print(Time)
    Light = "on"
    print("test")

    while True:
        if (Time + 5) < time():
            Time = time()         
            print(Time)
            print(Time+5)
            client = mqtt.Client()
            client.on_connect = on_connect
            client.on_message = on_message
            client.username_pw_set(username=MQTT_USER, password = MQTT_PASSWORD) 
            client.connect(MQTT_HOST, port=1883)
            #sleep(60 - time() % 60)
            print("loopdy loop")
            client.loop_start()
           
            if Light == "on":
                client.publish("ItechExample/LedControll","off")
                Light = "off"
                print("buttonstate: " + Light)
               
            elif Light == "off":
                client.publish("ItechExample/LedControll","on")
                Light = "on"
                print("buttonstate: " + Light)
            
            client.loop_stop()
        

#def my_subscribe(client, message_store = None):
#    client.subscribe("ItechExample/ButtonPressed")


    
client = my_connect()
#my_subscribe(client)



print("test")
