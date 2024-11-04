import time
import RPi.GPIO as gp

gp.setmode(gp.BCM)
gp.setup(4, gp.IN)

while True:
    data = gp.input(4)
    print(data)
    if data == 1:
        print("OBJECT IS not there")
    else:
        print("object!!!!")
    time.sleep(1)




