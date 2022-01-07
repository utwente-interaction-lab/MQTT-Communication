import paho.mqtt.client as mqtt


#credentials used for connecting to the MQTT broker. These have to be changed to your own.
MQTT_HOST = "192.168.1.101" #ip of the MQTT broker
MQTT_USER = "ItechLab" #User created for MQTT broker
MQTT_PASSWORD = "ItechLab" #Password for the created MQTT Broker



#Things the code has to do when it has connected to the broker
def on_connect(client, userdata,flags,rc):
    print("Connected with result code "+str(rc))
    client.subscribe("ItechExample/ButtonPressed")

#things the programm does when a message is received on one of the subscribed topics
def on_message(client, userdata, msg):
    print(msg.topic+" "+str(msg.payload))

#Function that does all the stuff for connecting to the broker    
def my_connect():
    client = mqtt.Client()
    client.on_connect = on_connect
    client.on_message = on_message
    client.username_pw_set(username=MQTT_USER, password = MQTT_PASSWORD)
    client.connect(MQTT_HOST, port=1883)
    client.loop_start()

client = my_connect()

print("test")
