import RPi.GPIO as IO
import time
compensation= 20

fichier = open("/home/pi/Desktop/Projet/Tests/PWM_servo_config.txt","r")  

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
cycle = (angle*5/(120-compensation))+5

p.ChangeDutyCycle(cycle)
time.sleep(0.5)

file = open("/home/pi/Desktop/Projet/Tests/flag.txt","w")

file.write("1")

file.close




