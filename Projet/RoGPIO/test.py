import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BOARD)
GPIO.setup(12, GPIO.OUT)
GPIO.setwarnings(False)

p = GPIO.PWM(12,50)
p.start(0)

while 1:

    p.ChangeDutyCycle(5)
    time.sleep(1.5)
    p.ChangeDutyCycle(7.5)
    time.sleep(1.5)
    p.ChangeDutyCycle(10)
    time.sleep(1.5)
    
