#ifndef DEF_ROGPIO

#include "RoGPIO.cpp"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#endif // DEF_ROGPIO
using namespace std;
void attente(void);

int main(void)
{
	GPIO servo_1;
	char test = 0;

	while(1)
	{

		
		test = bluetouche();
		
		if (test == '1') //Avancer
		{
			servo_1.ecrire_PWM(12,0);
			cout << test << "\n"<<endl;
			attente();
		}
		if (test == '2') //Gauche
		{
                        cout << test << "\n"<<endl;
			servo_1.ecrire_PWM(12,45);
			attente();
		}
		if (test == '3') //Droite
		{
		        cout << test << "\n"<<endl;
			servo_1.ecrire_PWM(12,90);
			attente();
		}
		if (test == '4') //Reculer
		{
                      	cout << test << "\n"<<endl;
			servo_1.ecrire_PWM(12,120);
			attente();
		}
		if (test == '0') // lel skkrrra
		{
			
		}

	sleep(1);
	}

	return 0;
}


void attente(void)
{
		char x=0;
		ifstream flagaf ("/home/pi/Desktop/Projet/Tests/flag.txt",ios::in); 


		if(flagaf)
		{
			while(x!='1')
			{
				flagaf.seekg(0,ios::beg);
				flagaf.get(x);
				
			}
			flagaf.close();
			cout << "lel : " << x << "\n" << endl;
		}

		else
		{
			cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;

		}

		ofstream file ("/home/pi/Desktop/Projet/Tests/flag.txt",ios::trunc);

		if (file)
		{
			file.close();

		}
		else
		{
			cout<< "ERREUR : Impossible d'ouvrir le fichier." << endl;
		}
		

}
