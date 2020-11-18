#include <stdio.h>
#include <stdlib.h>
#include "tab.h"


#define TAB2SIZE 100
#define TAILLEAJOUT 50

void main() {

	//Creation du tableau statique 1 et initialisation de ses termes � 0
	int myTab1[10];
	initTab(myTab1, 10);
	afficheTab(myTab1, 10, 10);
	printf("\n\n");

	//Creation du tableau dynamique 2 et initialisation de ses 20 premiers termes � 0
	int* myTab2 = NULL;

	myTab2 = (int*) malloc( TAB2SIZE * sizeof(int));

	if (myTab2 != NULL) { 
		initTab(myTab2, 20); 
	}
	else { 
		printf("m�moire insuffisante"); 
	}

	afficheTab(myTab2,TAB2SIZE,21); //j'affiche jusqu'� la 21�me valeur pour �tre s�r de ne pas avoir initialis� plus que les 20 premi�res valeurs
	free(myTab2); //On lib�re l'espace m�moire pris par le tableau 2

	printf("\n\n");

	// Cr�ation du tableau dynamique 3 et ajout d'un �l�ment � celui-ci
	int* myTab3 = NULL;

	myTab3 = (int*)malloc(30 * sizeof(int));

	if (myTab3 != NULL) {
		initTab(myTab3, 30); 
		}
	else {
		printf("m�moire insuffisante");
	}

	int* Size = 30;
	int* NbElts = 30;

	ajoutElementDansTableau(myTab3, &Size, &NbElts, 4);
	afficheTab(myTab3, &Size, 31); //on regarde si la fonction a bien rajout� un "4" � la suite soit � la 30�me place (en commen�ant � 0) ce qui est le cas

	ajoutElementDansTableau(myTab3, &Size, &NbElts, 4);
	afficheTab(myTab3, &Size, 32); //on regarde si la fonction a bien rajout� un "4" � la suite soit � la 31�me place (en commen�ant � 0) ce qui est le cas
	//le programme prend donc en compte l'augmentation de la taile et du nombre d'�l�ments comme souhait� en mettant des pointeurs comme arguments

	printf("\n\n");
	system("pause");
	free(myTab3);
}