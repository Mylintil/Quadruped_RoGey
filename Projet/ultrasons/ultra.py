import time
import RPi.GPIO as IO

IO.setmode(IO.BOARD)

#on definit des noms pour les pins utilises

IO_TRIGGER = 12
IO_ECHO = 11

# on regle  les pins en entres ou en sorties 

IO.setup(IO_TRIGGER,IO.OUT)
IO.setup(IO_ECHO,IO.IN)

#On met le trigger a 0

IO.output(IO_TRIGGER, False)

time.sleep(0.5)

#on envoie 10 microsecodes sur le trigger pour lancer la mesure 

IO.output(IO_TRIGGER, True)
time.sleep(0.00001)  #10microsecondes 
IO.output(IO_TRIGGER, False)

#attente de la reponse du capteur 

while IO.input(IO_ECHO) == 0:

	debut = time.time()

while IO.input(IO_ECHO) == 1:

	fin = time.time()

#Duree de l'impulsion 

duree = fin-debut

#distance = duree * vitesse du son (340m/s = 34000cm/s) / 2 car aller/retour 

distance =  (duree * 34000)/2

print "Distance mesuree : %1f" %distance  


