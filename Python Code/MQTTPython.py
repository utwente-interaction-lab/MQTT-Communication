
# libraries need for the mqtt parts and the time based functions
import paho.mqtt.client as mqtt
import time


MQTT_HOST = "192.168.0.3" # put here the ip adderes of the mqtt broker (mosquitto). If this not made static in the router it can change
MQTT_USER = "test" # user you created in mosquitto
MQTT_PASSWORD = "test" # Password connected with that user


# function where things can be put that have to be done when there is a connection with MQTT made
# can be handy for subscribing
def on_connect(client, userdata,flags,rc):
    print("Connected with result code "+str(rc))
    client.subscribe("ItechExample/ButtonPressed",2)

#function that is called when a message received. You can use things related to the received message in here
def on_message(client, userdata, msg):
    print(msg.topic+" "+str(msg.payload))


def my_connect():
    #variable related to tracking runtime
    Time = time.time()
    print(Time)
    Light = "on"

    #loop to ensure all mqtt stuff keeps on being done. runs forever until you press ctrl + c in the console. messes with other functions outside the loop that are selfmade and not in this example.
    while True:
        #makes a so everything inside this of statement is run once every 5 seconds
        if (Time + 5) < time.time():
            Time = time.time()
            print("start time: " + Time)
            #functions related to connecting with mqtt
            client = mqtt.Client()
            client.on_connect = on_connect
            client.on_message = on_message
            client.username_pw_set(username=MQTT_USER, password = MQTT_PASSWORD)
            #if you use a different port for mosquitto/mqtt you can change the 1883.
            client.connect(MQTT_HOST, port=1883)
            #sleep(60 - time() % 60)
            print("starting loop")
            #start the loop of sending messages and receiving them
            client.loop_start()
            #statement that toggles the led on the other controller
            if Light == "on":
                client.publish("ItechExample/LedControll","off")
                Light = "off"
                print("buttonstate: " + Light)

            elif Light == "off":
                client.publish("ItechExample/LedControll","on")
                Light = "on"
                print("buttonstate: " + Light)
            #wait 4 seconds to receive message from mosquitto/MQTT
            time.sleep(4);
            print("stoping loop")
            #stops the loop with receiving and sending messages
            client.loop_stop()

#start the main function and connects all function in the right way
client = my_connect()
my_subscribe(client)
