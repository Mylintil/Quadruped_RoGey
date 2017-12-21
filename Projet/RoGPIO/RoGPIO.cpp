#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;

string bluetouche (void);

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

string bluetouche (void)
	{
		string x;
		char Text[50];

		ifstream commande ("/home/pi/Desktop/Projet/RiGPIO/blue.txt");  

	
		if(commande)
		{
			commande >> x;	
	
		}

		else
		{
			cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;	

		}

		commande.close();
	
		sprintf(Text,"sudo echo "" > blue.txt");
		system(Text);
	
		return x;



	}

