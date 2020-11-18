#include <stdio.h>
#include <stdlib.h>
#include "tab.h"


#define TAB2SIZE 100
#define TAILLEAJOUT 50

void main() {

	//Creation du tableau statique 1 et initialisation de ses termes à 0
	int myTab1[10];
	initTab(myTab1, 10);
	afficheTab(myTab1, 10, 10);
	printf("\n\n");

	//Creation du tableau dynamique 2 et initialisation de ses 20 premiers termes à 0
	int* myTab2 = NULL;

	myTab2 = (int*) malloc( TAB2SIZE * sizeof(int));

	if (myTab2 != NULL) { 
		initTab(myTab2, 20); 
	}
	else { 
		printf("mémoire insuffisante"); 
	}

	afficheTab(myTab2,TAB2SIZE,21); //j'affiche jusqu'à la 21ème valeur pour être sûr de ne pas avoir initialisé plus que les 20 premières valeurs
	free(myTab2); //On libère l'espace mémoire pris par le tableau 2

	printf("\n\n");

	// Création du tableau dynamique 3 et ajout d'un élément à celui-ci
	int* myTab3 = NULL;

	myTab3 = (int*)malloc(30 * sizeof(int));

	if (myTab3 != NULL) {
		initTab(myTab3, 30); 
		}
	else {
		printf("mémoire insuffisante");
	}

	int* Size = 30;
	int* NbElts = 30;

	ajoutElementDansTableau(myTab3, &Size, &NbElts, 4);
	afficheTab(myTab3, &Size, 31); //on regarde si la fonction a bien rajouté un "4" à la suite soit à la 30ème place (en commençant à 0) ce qui est le cas

	ajoutElementDansTableau(myTab3, &Size, &NbElts, 4);
	afficheTab(myTab3, &Size, 32); //on regarde si la fonction a bien rajouté un "4" à la suite soit à la 31ème place (en commençant à 0) ce qui est le cas
	//le programme prend donc en compte l'augmentation de la taile et du nombre d'éléments comme souhaité en mettant des pointeurs comme arguments

	printf("\n\n");
	system("pause");
	free(myTab3);
}