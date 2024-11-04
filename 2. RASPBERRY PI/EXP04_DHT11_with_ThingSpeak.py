import Adafruit_DHT as dht
import time
import requests
sensor = dht.DHT11

def send_data(t,h):
    base_url = "https://api.thingspeak.com/update?"
    key = "YBDOZTGD1HA2AQRN"
    parameters = "&field1="+str(t)+"&field2="+str(h)
    url = base_url + "api_key="+key+parameters
    result = requests.get(url)
    print("Data Sent:",result.text)

while True:
    humid,temp = dht.read_retry(sensor,3)
    if humid is not None and temp is not None:
        print("Temperature:",temp,"*C")
        print("Humidity:",humid,"%")
        send_data(temp,humid)
        time.sleep(15)
    else:
        print("Unable to read sensor data")
        