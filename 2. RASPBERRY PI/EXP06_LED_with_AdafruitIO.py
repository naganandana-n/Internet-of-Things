import RPi.GPIO as gp
from Adafruit_IO import MQTTClient
import sys
key = "b583f8cbef00474481f4bce7b076e1f7"
user =  "jagnayak"
gp.setmode(gp.BCM)
gp.setup(2,gp.OUT)

def mqtt_connect(client):
    print("Subscribing to feed...")
    client.subscribe('light')
    print("Subscribed to Feed")
    print("Waiting for the data")
    
def mqtt_disconnect(client):
    sys.exit()
    
def mqtt_data(client,feed,msg):
    print(msg)
    if msg == "Bright":
        gp.output(2,True)
        print("LED ON")
    if msg == "Dim":
        gp.output(2,False)
        print("LED OFF")
    
client = MQTTClient(user,key)
client.on_connect = mqtt_connect
client.on_disconnect = mqtt_disconnect
client.on_message = mqtt_data
client.connect()
client.loop_blocking()   ## run continuosly in the background