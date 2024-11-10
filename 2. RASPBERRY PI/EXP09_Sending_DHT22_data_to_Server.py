import Adafruit_DHT as dht
import requests
import time

DHT_SENSOR = dht.DHT22
DHT_PIN = 4  

# Define the base URL for sending data
base_url = "http://3.29.135.164/myinsert.php"

while True:
    
    humidity, temperature = dht.read_retry(DHT_SENSOR, DHT_PIN)
    
    # Check if readings are valid
    if humidity is not None and temperature is not None:
        # Convert readings to integers
        humidity = int(humidity)
        temperature = int(temperature)
        
        # Prepare the payload with integer values
        payload = {
            'h': humidity,   # Integer humidity
            't': temperature # Integer temperature
        }
        
        # Send data to the server using GET request
        response = requests.get(base_url, params=payload)

        # Send data to the server using GET request
        try:
            response = requests.get(base_url, params=payload) # response is the result of this request
            print(f"Sent data: {payload} - Response code: {response.status_code}") # 200 status code for success
        except requests.RequestException as e:
            # requests.RequestException is a generic exception that catches any errors related to the HTTP request.
            print("Failed to send data:", e)
        
        '''
        YOU CAN DO THIS INSTEAD OF THE TRY EXCEPT

        # Check the response status code
        if response.status_code == 200:
            print(f"Sent data: {payload} - Response code: {response.status_code}")
        else:
            print(f"Failed to send data, response code: {response.status_code}")
        '''
        
    else:
        print("Failed to retrieve data from DHT22 sensor")
    
    # Wait for a while before reading again (e.g., 60 seconds)
    time.sleep(5)