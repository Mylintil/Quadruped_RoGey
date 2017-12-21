import RPi.GPIO as IO
import time
compensation= 20
i=1
y=0
fichier = open("PWM_servo_config.txt","r")  

contenu = fichier.read()
tab = contenu.split('_')
tab_pin=['1','2','3','4','5','6','7','8']
tab_cycle=[0,0,0,0,0,0,0,0]
nombre = int(tab[0])

while (y<17):
	tab[y] = int(tab[y])
	y+=1
y=0
#pin = int(tab[0])
#angle = int(tab[1])


fichier.close()

IO.setwarnings(False)
IO.setmode(IO.BOARD)

while (i<(nombre+1)):
	IO.setup(tab[2*i-1],IO.OUT)
	tab_pin[i-1] = IO.PWM(tab[2*i-1],50)
	tab_pin[i-1].start(0)
	tab_cycle[i-1] = ((tab[2*i])*5/(120-compensation))+5
	tab_pin[y].ChangeDutyCycle(tab_cycle[y])
	i=i+1
	y+=1
	

i=0
y=0

time.sleep(0.5)

file = open("flag.txt","w")

file.write("1")

file.close





