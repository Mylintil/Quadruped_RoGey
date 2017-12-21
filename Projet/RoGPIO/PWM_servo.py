import RPi.GPIO as IO
import time


fichier = open("/home/pi/Desktop/Projet/RoGPIO/PWM_servo_config.txt","r")  

contenu = fichier.read()
tab = contenu.split('_')
pin = int(tab[0])
angle = int(tab[1])

fichier.close()

IO.setwarnings(False)
IO.setmode(IO.BOARD)
IO.setup(pin,IO.OUT)

p = IO.PWM(pin,50)
p.start(0)
cycle = angle/180 + 1
cycle = cycle*100/20

p.ChangeDutyCycle(cycle)
time.sleep(1)

