import paho.mqtt.client as mqtt

MQTT_HOST = "192.168.1.101"
MQTT_USER = "ItechLab"
MQTT_PASSWORD = "ItechLab"

def on_connect(client, userdata,flags,rc):
    print("Connected with result code "+str(rc))
    client.subscribe("ItechExample/ButtonPressed")

def on_message(client, userdata, msg):
    print(msg.topic+" "+str(msg.payload))

def my_connect():
    client = mqtt.Client()
    client.on_connect = on_connect
    client.on_message = on_message
    client.username_pw_set(username=MQTT_USER, password = MQTT_PASSWORD)
    client.connect(MQTT_HOST, port=1883)
    client.loop_start()


#def my_subscribe(client, message_store = None):
#    client.subscribe("ItechExample/ButtonPressed")

client = my_connect()
#my_subscribe(client)

print("test")
