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
	void exporter(char pin)
	{

		char Text[50];
		sprintf(Text, "sudo echo %d > /sys/class/gpio/export", pin);
		system(Text);
		usleep(1000);
	}
	void importer(char pin)
	{
		char Text[50];
		sprintf(Text, "sudo echo %d > /sys/class/gpio/unexport", pin);
		system(Text);
	}

	void mode(char pin, char sens)
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
			sprintf(Text, "Erreur");
		}
		system(Text);
        }

	void ecrire(char pin, char val)
	{
		char Text[50];
		sprintf(Text,"sudo echo %d > /sys/class/gpio/gpio%d/value", val, pin);
		system(Text);

	}

	void ecrire_PWM(char pin,char angle)
	{
		char Text[50];
		if (angle <= 180 )
		{
			ofstream fichier("PWM_servo_config.txt", ios::out | ios::trunc);
			sprintf(Text, "%d_%d", pin, angle);
			fichier << Text;
			fichier.close();
			system("sudo python PWM_servo.py");
		}
		else
		{
			system("echo Angle non valide");
		}

	}


};

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

