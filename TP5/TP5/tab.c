#include <stdio.h>
#include <stdlib.h>

#define TAILLEAJOUT 50
//fonction qui permet d'initialiser chaque terme à 0 si sa taille est non négative ou nulle et si le tableau n'est pas égal à NULL
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
//fonction qui permet d'afficher les nbElts premiers termes si sa taille est non négative ou nulle et si le tableau n'est pas égal à NULL
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

//fonction qui permet d'ajouter un élément au tableau dynamique en réallouant de l'espace dans celui-ci si nécessaire
int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	
	if (*size < 0) {
		return NULL;
	}
	if (tab == NULL) {
		return NULL;
	}
	if (*nbElts < *size) {// S'il y a la place nécessaire on rajoute juste l'élément à la fin
		tab[*nbElts] = element;//on ajoute l'élément à la fin du tableau
		*nbElts = *nbElts + 1;//on oublie pas d'augmenter le nombre d'éléments
		return tab;
	}
	else {
		int* tmp= NULL;

		tmp = (int*)realloc(tab, (*size + TAILLEAJOUT) * sizeof(int)); //S'il n'y a pas la mémoire nécessaire dans le tableau de base,
		//on utilise la fonction realloc qui permet d'allouer plus d'espace tout en ne modifiant pas le tableau de base, on utilise un pointeur temporaire
		//pour ne pas prendre le risque de perdre le tableau initial si la fonction realloc ne fonctionne pas

		if (tmp == NULL) { //Si la fonction realloc n'alloue pas la place demandée c'est que la mémoire est insuffisante
			printf("memoire insuffisante");
			return NULL;
			
		}
		else {
			tab = tmp;//comme tmp n'est pas nul cela signifie que la fonction realloc a pu allouer la mémoire nécessaire, donc on récupère 
			//le pointeur temporaire via le tableau initial
			tmp[*nbElts] = element;//on ajoute l'élément à la fin du tableau
			*size = *size + TAILLEAJOUT;
			*nbElts = *nbElts + 1; //on oublie pas d'augmenter le nombre d'éléments et la taille du tableau
			return tab;
		}
	}
}
