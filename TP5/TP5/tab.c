#include <stdio.h>
#include <stdlib.h>

#define TAILLEAJOUT 50
//fonction qui permet d'initialiser chaque terme � 0 si sa taille est non n�gative ou nulle et si le tableau n'est pas �gal � NULL
int initTab(int* tab, int size) {

	if (size < 0) {
		return -1;
	}
	if (tab==NULL){
		return -1;
	}
	else {
		for (int i = 0; i < size; i++) {
			tab[i] = 0;
		}
		return size;
	}
}
//fonction qui permet d'afficher les nbElts premiers termes si sa taille est non n�gative ou nulle et si le tableau n'est pas �gal � NULL
int afficheTab(int* tab, int size, int nbElts) {

	if (size < 0) {
		return -1;
	}
	if (size < nbElts) {
		return -1;
	}
	if (tab == NULL) {
		return -1;
	}
	else {
		for (int i = 0; i < nbElts; i++) {
			printf("%d ", tab[i]);
		}
		return 0;
	}
}

//fonction qui permet d'ajouter un �l�ment au tableau dynamique en r�allouant de l'espace dans celui-ci si n�cessaire
int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	
	if (*size < 0) {
		return NULL;
	}
	if (tab == NULL) {
		return NULL;
	}
	if (*nbElts < *size) {// S'il y a la place n�cessaire on rajoute juste l'�l�ment � la fin
		tab[*nbElts] = element;//on ajoute l'�l�ment � la fin du tableau
		*nbElts = *nbElts + 1;//on oublie pas d'augmenter le nombre d'�l�ments
		return tab;
	}
	else {
		int* tmp= NULL;

		tmp = (int*)realloc(tab, (*size + TAILLEAJOUT) * sizeof(int)); //S'il n'y a pas la m�moire n�cessaire dans le tableau de base,
		//on utilise la fonction realloc qui permet d'allouer plus d'espace tout en ne modifiant pas le tableau de base, on utilise un pointeur temporaire
		//pour ne pas prendre le risque de perdre le tableau initial si la fonction realloc ne fonctionne pas

		if (tmp == NULL) { //Si la fonction realloc n'alloue pas la place demand�e c'est que la m�moire est insuffisante
			printf("memoire insuffisante");
			return NULL;
			
		}
		else {
			tab = tmp;//comme tmp n'est pas nul cela signifie que la fonction realloc a pu allouer la m�moire n�cessaire, donc on r�cup�re 
			//le pointeur temporaire via le tableau initial
			tmp[*nbElts] = element;//on ajoute l'�l�ment � la fin du tableau
			*size = *size + TAILLEAJOUT;
			*nbElts = *nbElts + 1; //on oublie pas d'augmenter le nombre d'�l�ments et la taille du tableau
			return tab;
		}
	}
}
