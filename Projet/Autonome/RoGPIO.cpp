#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <unistd.h>

using namespace std;

char bluetouche (void);

class GPIO
{
	public:
	void exporter(char pin)  //Activation d'un Pin
	{

		char Text[50];
		sprintf(Text, "sudo echo %d > /sys/class/gpio/export", pin);
		system(Text);
		usleep(1000);
	}
	void importer(char pin) //Désactivation d'un Pin 
	{
		char Text[50];
		sprintf(Text, "sudo echo %d > /sys/class/gpio/unexport", pin);
		system(Text);
	}

	void mode(char pin, char sens) //Definir Pin entre ou sortie 
        {
                char Text[50];
		if ( sens == 'o')
		{
			sprintf(Text, "sudo echo out > /sys/class/gpio/gpio%d/direction", pin);
		}
		else if ( sens == 'i')
		{
			sprintf(Text, "sudo echo in > /sys/class/gpio/gpio%d/direction", pin);

		}
		else
		{
			sprintf(Text, "sudo echo Erreur");
		}
		system(Text);
        }

	void ecrire_PWM(char *t)   //Lance le fichier python gerant les servos
	{
		char Text[500];
		if (t[2] <= 120 )
		{

			ofstream fichier("PWM_servo_config.txt", ios::out | ios::trunc);
			sprintf(Text, "%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d",t[0],t[1],t[2],t[3],t[4],t[5],t[6],t[7],t[8],t[9],t[10],t[11],t[12],t[13],t[14],t[15],t[16]);
			fichier << Text;
			fichier.close();
			system("sudo python PWM_servo.py");
		}
		else
		{
			system("echo Angle non valide");
		}
	}

	

	void ecrire(char pin, char val) //Met à 1 ou 0 un Pin 
	{
		char Text[50];
		sprintf(Text,"sudo echo %d > /sys/class/gpio/gpio%d/value", val, pin);
		system(Text);

	}


	void lire(char pin) //Copie l'état de la pin dans un fichier
	{
		char Text[50];
		sprintf(Text, "cp /sys/class/gpio/gpio%hd/value lecture_GPIO.txt", pin);
		system(Text);
	}
		


};

//Lecture du fichier texte de la liaison serie bluetooth 
char bluetouche (void)
	{
		char x;
		ifstream commande ("/home/pi/Desktop/Projet/Tests/blue.txt",ios::in); 


		if(commande)
		{
			commande.seekg(0,ios::beg); //Positionnement au début + '0' caractères
			commande.get(x); 
			commande.close();

		}

		else
		{
			cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;

		}

		ofstream file ("/home/pi/Desktop/Projet/Tests/blue.txt",ios::trunc);

		if (file)
		{
			file.close();
		}
		else
		{
			cout<< "ERREUR : Impossible d'ouvrir le fichier." << endl;
		}
		return x;



	}

