#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;

string fonction(void);

int main(void)
{
	string y;
	
	while(1)
	{
		y = fonction();
		cout << "  " <<y<<endl;
		usleep(1000000);
	
	}

	return 0;

}


string fonction(void)
{

	string x;
	char Text[50];

	ifstream commande ("/home/pi/Desktop/Projet/test.txt");  

	
	if(commande)
	{
		commande >> x;	
	
	}

	else
	{
		// cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;	

	}

	commande.close();
	
	sprintf(Text,"sudo echo "" > test.txt");
	system(Text);
	
	return x;
	

}

