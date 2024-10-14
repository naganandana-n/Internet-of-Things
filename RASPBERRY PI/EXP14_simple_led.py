import time
import RPi.GPIO as gp

gp.setmode(gp.BCM)
gp.setup(2, gp.OUT)

while True:
    gp.output(2, True)
    print("LED ON")
    time.sleep(1)
    gp.output(2, False)
    print("LED OFF")
    time.sleep(1)
