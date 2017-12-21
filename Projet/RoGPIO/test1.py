import RPi.GPIO as IO
import time

fichier = open("PWM_servo_config.txt",r)  //r = read ; w = write ;

contenu = fichier.read()
tab = contenu.split('_')
pin = int(tab[0])
angle = int(tab[1])

fichier.close()

IO.setwarnings(False)
IO.setmode(IO.BOARD)
IO setup(pin,IO.OUT)

p = IO.PWM(pin,50)
p.start(0)
float  cycle = angle/180 + 1
cycle = cycle*100/20

p.ChangeDutyCycle(cycle)
time.sleep(2)

