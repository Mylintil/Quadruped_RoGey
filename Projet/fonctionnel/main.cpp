#ifndef DEF_ROGPIO

#include "RoGPIO.cpp"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#endif // DEF_ROGPIO
using namespace std;

void attente(void);// En commentaire car non utilisé; Utile ?

int main(void)
{

	GPIO servos;	//Classe pour accéder aux fonctions de la bibliothèque
	char Var = 0;
	char tab1[17] = {2,7,0,12,0,15,0,18,60,0,0,0,0,0,0,0,0};	//Tab[] pour mouvement servos
	char tab2[17] = {2,7,60,12,60,15,60,0,0,0,0,0,0,0,0,0,0};
	char tab3[17] = {2,7,90,12,60,15,60,0,0,0,0,0,0,0,0,0,0};
	char tab4[17] = {2,7,120,12,0,15,0,0,0,0,0,0,0,0,0,0,0};
	
	char tab_calibre[17] ={1,12,60,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	char tab_test[17] = {1,12,120,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	char tab_test2[17] = {1,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	while(1)
	{
		servos.ecrire_PWM(&tab_calibre[0]);
		attente();
		servos.ecrire_PWM(&tab_test[0]);
		attente();
		servos.ecrire_PWM(&tab_calibre[0]);
		attente();
		servos.ecrire_PWM(&tab_test2[0]);
		attente();
		/*servos.ecrire_PWM(&tab1[0]);
		attente();
		servos.ecrire_PWM(&tab2[0]);
		attente();
		servos.ecrire_PWM(&tab3[0]);
		attente();
		servos.ecrire_PWM(&tab4[0]);
		attente();
		
		/*
		/*if (Var!=0)
		{
			servos.ecrire_PWM(&tab1[0]); //Lancement des mouvements de premier tableau
			attente();
		}
		else
		{
                        servos.ecrire_PWM(&tab2[0]); //Lancement des mouvements de second tableau
			attente();
		}
		Var = !Var;
		*/
	}



}




void attente(void)
{
                char x=0;
                ifstream flagaf ("flag.txt",ios::in); 


                if(flagaf)
                {
                        while(x!='1')
                        {
                                flagaf.seekg(0,ios::beg);
                                flagaf.get(x);

                        }
                        flagaf.close();

                }

                else
                {
                        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;

                }

                ofstream file ("flag.txt",ios::trunc);

                if (file)
                {
                        file.close();

                }
                else
                {
                        cout<< "ERREUR : Impossible d'ouvrir le fichier." << endl;
                }


}

