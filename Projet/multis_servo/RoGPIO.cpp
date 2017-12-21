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

	void ecrire_PWM(char nombre,char pin_1,char angle_1,char pin_2,char angle_2,char pin_3,char angle_3,char pin_4,char angle_4,char pin_5,char angle_5,char pin_6,char angle_6,char pin_7,char angle_7,char pin_8,char angle_8)
	{
		char Text[500];
		if (angle_1 <= 120 )
		{

			ofstream fichier("PWM_servo_config.txt", ios::out | ios::trunc);
			sprintf(Text, "%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d",nombre, pin_1, angle_1, pin_2, angle_2, pin_3, angle_3, pin_4, angle_4, pin_5, angle_5, pin_6, angle_6, pin_7, angle_7, pin_8, angle_8);
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

