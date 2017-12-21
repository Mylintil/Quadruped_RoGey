#ifndef DEF_ROGPIO

#include "RoGPIO.cpp"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#endif //Def_ROGPIO
using namespace std;

signed short lecture_distance(void);

void lancement_mesure (void);

int  main(void)
{
	signed short distance=0;

	while(1)
	{
		lancement_mesure();
		distance = lecture_distance();
		cout << "distance : " <<distance<<endl;
		sleep(1);
	}

	return 0 ;
}

signed short  lecture_distance(void)
{
	//Distance toujours écrite sur 3 caracteres (en cm)

	signed short mesure = 0;
	char  distance[3];

	ifstream lect_dist("dist.txt",ios::in);

	if(lect_dist)
	{
		lect_dist.seekg(0,ios::beg);
		lect_dist.get(distance[0]);
		lect_dist.get(distance[1]);
		lect_dist.get(distance[2]);


		lect_dist.close();
	}
	else
	{
		cout << "ERREUR : impossible d'ouvrir dist.txt" << endl;
	}

	ofstream efface("dist.txt",ios::trunc);

	if("efface")
	{
		efface.close();
	}
	else
	{
		cout << "ERREUR : impossible d'effacer le contenu de dist.txt" << endl;
	}

	mesure = (distance[0]-48)*100+(distance[1]-48)*10+(distance[2]-48);
	return mesure;
}

void lancement_mesure(void)
{
	system("sudo python ultra.py");
}
