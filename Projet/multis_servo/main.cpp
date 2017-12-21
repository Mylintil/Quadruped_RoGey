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
	GPIO servo_2;
	char Var = 0;
	while(1)
	{
		if (Var!=0)
		{
			servo_2.ecrire_PWM(2,11,120,12,0,0,0,0,0,0,0,0,0,0,0,0,0);
			//servo_1.ecrire_PWM(12,0);

			//attente();
		}
		else
		{
                        servo_2.ecrire_PWM(2,11,0,12,120,0,0,0,0,0,0,0,0,0,0,0,0);//('nb pin utilisé','pin1','cycle1','pin2','cycle2',[...])
			//servo_1.ecrire_PWM(12,120);
			//attente();
		}
		Var = !Var;
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
                        //cout << "lel : " << x << "\n" << endl;
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


