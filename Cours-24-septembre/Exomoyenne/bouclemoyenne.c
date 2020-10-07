#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void main() {
	int somme = 0;
	int i=0;
	int nbdenb = 0;
	float moyenne = 0;

	while (i != -1) {
		printf("Donner un nombre \n");
		scanf_s("%d", &i);
		somme = somme + i;
		nbdenb = nbdenb + 1;
	}
	moyenne = (float)somme / (float)nbdenb;
	printf("La valeur de la moyenne est %f\n", moyenne);
	system("pause");
}