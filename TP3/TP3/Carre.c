#include <stdlib.h>
#include <stdio.h>

#define carre(x) (x) * (x) // pour que la macro fonctionne il suffit de mettre des parenth�ses pour qu'elle prenne bien en compte "x" tel qu'il est r�ellement

void main() {

	int Nb = 5;

	printf("%d\n", carre(Nb)); //on obtient 25, aucun probl�me

	printf("%d\n", carre(Nb+1)); // on obtient 11, il y a un probl�me qui vient probablement du fait que "Nb+1" soit un calcul et que la macro ne prenne pas bien
	// en compte la valeur car elle est constitu� de 3 caract�res

}