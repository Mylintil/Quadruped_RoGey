import RPi.GPIO as IO
import time
compensation= 20

IO.setwarnings(False)
IO.setmode(IO.BOARD)

IO.setup(11,IO.OUT)
IO.setup(12,IO.OUT)

p = IO.PWM(11,50)
s = IO.PWM(12,50)

p.start(0)
s.start(0)

angle1 = (120*5/(120-compensation))+5
angle2 = (2*5/(120-compensation))+5
print(angle1)
print(angle2)

while(1):
	
	p.ChangeDutyCycle(angle1)
	s.ChangeDutyCycle(angle2)
	time.sleep(1)
	s.ChangeDutyCycle(angle1)
	p.ChangeDutyCycle(angle2)
	time.sleep(1)
