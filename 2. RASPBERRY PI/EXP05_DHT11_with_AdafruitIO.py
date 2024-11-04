import Adafruit_DHT as dht
import time
from Adafruit_IO import Client
sensor = dht.DHT11
key = "aio_dXOo11MDUVOdFOf76vUrIamGJ8x2"
user =  "jagIoT"
client = Client(user,key)   ## authenticate the account
hum_feed = client.feeds('Humidity')
temp_feed = client.feeds('Temperature')

def send_data(h,t):
    client.send_data(hum_feed.key,h)
    client.send_data(temp_feed.key,t)
    print("Data Published")
    
while True:
    hum,temp = dht.read_retry(sensor,3)
    if hum is not None and temp is not None:
        print("Temperature:",temp,"*C")
        print("Humidity:",hum,"%")
        send_data(hum,temp)
        time.sleep(5)
    else:
        print("Unable to read sensor data")