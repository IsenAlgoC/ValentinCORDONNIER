#include <stdlib.h>
#include <stdio.h>

#define carre(x) (x) * (x) // pour que la macro fonctionne il suffit de mettre des parenthèses pour qu'elle prenne bien en compte "x" tel qu'il est réellement

void main() {

	int Nb = 5;

	printf("%d\n", carre(Nb)); //on obtient 25, aucun problème

	printf("%d\n", carre(Nb+1)); // on obtient 11, il y a un problème qui vient probablement du fait que "Nb+1" soit un calcul et que la macro ne prenne pas bien
	// en compte la valeur car elle est constitué de 3 caractères

}