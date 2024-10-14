import Adafruit_DHT as dht
import time
sensor = dht.DHT11
while True:
    humid, temp = dht.read_retry(sensor, 3)
    if humid is not None and temp is not None:
        print("Temperature: ", temp, "* C")
        print("Humidity: ", humid, "%")
        time.sleep(5)
    else:
        print("Unable to read sensor data")