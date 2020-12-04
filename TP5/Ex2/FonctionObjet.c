#include <stdio.h>
#include <stdlib.h>
#include "objet.h"

#define TAILLEINITIALE 100

//Cr�er un nouveau TABLEAU en allouant une taille initiale pour les donn�es et en initialisant ses valeurs � 0
TABLEAU newArray() {

	TABLEAU MyTab;

	MyTab.elt = (int*)malloc(TAILLEINITIALE * sizeof(int)); //on alloue l'espace n�cessaire � la cr�ation du tableau
	MyTab.size = TAILLEINITIALE;
	MyTab.eltsCount = 0;

	for (int i = 0; i < MyTab.size; i++) {
		MyTab.elt[i] = 0;
	}
	return MyTab;
}

//Modifier la taille du tableau
int incrementArraySize(TABLEAU* tab, int incrementValue) {
	if (tab->elt == NULL || tab->size<0 ) {
		return -1;
	}
	int* tmp = NULL;

	tmp = (int*)realloc(tab->elt, (incrementValue + tab->size) * sizeof(int)); //on r�alloue l'espace n�cessaire pour le nouveau tableau
	
	if (tmp == NULL) { //Si la fonction realloc n'alloue pas la place demand�e c'est que la m�moire est insuffisante
		printf("Memoire insuffisante\n");
		return -1;
	}
	else {
		tab->elt = tmp;
		for (int i = tab->size - 1; i < tab->size + incrementValue; i++) { //On initialise l'espace allou� � 0  
			tab->elt[i] = 0;
		}
		tab->size = tab->size + incrementValue;
		return tab->size;
	}
}

//Ecrire un �l�ment � une position donn�e sans insertion, la valeur aux indices nouvellement ajout�s est initialis�e a 0
int setElement(TABLEAU* tab, int pos, int element) {

	// Pour pouvoir directement mettre la valeur � la position r�ellement voulue, on �crit pos-1 car le tableau commence au rang 0 et non 1
	if (tab->elt == NULL || tab->size < 0 || pos < 1 ) {
		return 0;
	}
	if (pos-1 < tab->size) { //Si la position demand�e est d�j� possible pour le tableau on affecte juste la valeur o� on le demande
		tab->elt[pos-1] = element;
		tab->eltsCount = tab->size;
		return pos;
	}
	else { /*Sinon on augmente la taille du tableau de la diff�rence entre la position voulue et sa taille actuelle pour ensuite
		rajouter la valeur � l'emplacement voulu*/
		incrementArraySize(tab, pos - tab->size);
		tab->elt[pos-1] = element;
		tab->eltsCount = pos;
		return pos;
	}
}

//Afficher une portion du tableau de l�indice d�but � l�indice fin
int displayElements(TABLEAU* tab, int startPos, int endPos) {
	if (tab->elt == NULL || tab->size < 0 || startPos < 1 || endPos < 1) {
		return -1;
	}
	else {
		if (startPos <= endPos) {
			for (int i = startPos - 1; i < endPos; i++) { //Pour pouvoir afficher directement les valeurs r�ellement voulues, on soustrait 1
				//car le tableau commence au rang 0 et non 1
				printf("%d ", tab->elt[i]);
			}
			return 0;
		}
		else {
			for (int i = startPos - 1; i >= endPos - 1; i--) { //Dans ce cas la boucle est en sens inverse pour pouvoir obtenir les �l�ments de
				// startPos � endPos
				printf("%d ", tab->elt[i]);
			}
			return 0;
		}
	}
}

int deleteElements(TABLEAU* tab, int startPos, int endPos) {
	if (tab->elt == NULL || tab->size < 0 || startPos < 1 || endPos < 1) {
		return -1;
	}
	/*L'ordre des param�tres n'influe pas sur cette fonction donc on s'assure que startpos reste inf�rieur � endPos*/
	if (endPos < startPos) {
		int tmp = endPos;
		endPos = startPos;
		startPos = tmp;
	}
	int nbVal = endPos - startPos + 1;
	//si l'on veut supprimer tous les �l�ments du tableau on lib�re totalement la place en m�moire
	if (nbVal == tab->size) {
		free(tab->elt);
		tab->elt = NULL;
		tab->size = 0;
		tab->eltsCount = 0;
		return tab->size;
	}
	/*On souhaite "d�caler" vers la gauche les �l�ments pour pouvoir ensuite supprimer la partie demand�e, donc on remplace ses �l�ments et 
	on supprimera ensuite l'espace qui n'est plus utile*/
	for (int i = startPos-1; i < tab->size - nbVal; i++) {
		tab->elt[i] = tab->elt[i + nbVal];
	}
	int* tmp = NULL;

	tmp = (int*)realloc(tab->elt, (tab->size-nbVal) * sizeof(int)); //on r�alloue l'espace n�cessaire pour le nouveau tableau

	if (tmp == NULL) { //Si la fonction realloc n'alloue pas la place demand�e c'est que la m�moire est insuffisante
		printf("Memoire insuffisante\n");
		return -1;
	}
	else {
		tab->elt = tmp;
		tab->size = tab->size - nbVal;
		return tab->size;
	}
}