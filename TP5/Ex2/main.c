#include <stdio.h>
#include <stdlib.h>
#include "objet.h"

#define TAILLEINITIALE 100

void main() {

	//Test de la fonction "newArray" et on l'affiche pour vérifier qu'elle soit constituée de 0
	TABLEAU MyTab; 
	MyTab = newArray();
	displayElements(&MyTab, 1, 100);
	printf("\n\n");

	//Test de la fonction "incrementArraySize" et on l'affiche pour vérifier qu'elle ait bien n (ici 5) valeurs de plus
	incrementArraySize(&MyTab, 5);
	displayElements(&MyTab, 1, 105);
	printf("\n\n");

	/*Test de la fonction "setElement" dans deux cas, un avec un élément à rajouter dans le tableau de façon habituelle et un 
	où il faut augmenter la taille du tableau, on l'affiche pour vérifier les positions et le fait qu'il y ait des 0 rajoutés entre le nombre 
	et l'élément rajouté à la fin*/
	setElement(&MyTab, 4, 87);
	setElement(&MyTab, 105, 854);
	displayElements(&MyTab, 1, 105);
	printf("\n\n");
	
	/*On vérifie que la fonction "displayElements" fonctionne aussi avec les paramètres inversés et qu'elle affiche effectivement 
	les nombres dans l'autre ordre*/
	displayElements(&MyTab, 105, 1);
	printf("\n\n");

	/*On vérifie que la fonction "deleteElements" fonctionne et on affiche le nombre d'éléments qui sont censés rester*/
	deleteElements(&MyTab, 5, 103);
	displayElements(&MyTab, 1, 6);
	printf("\n\n");

	/*On vérifie qu'elle effectue la même chose avec les paramètres inversés et on vérifie qu'elle donne en sortie la bonne taille du tableau*/
	setElement(&MyTab, 4, 87);
	setElement(&MyTab, 105, 854);
	int x=deleteElements(&MyTab, 103, 5);
	displayElements(&MyTab, 1, 6);
	printf("\n\n");

	printf("Taille finale du tableau = %d\n", x);

	system("pause");
	free(MyTab.elt);
}
