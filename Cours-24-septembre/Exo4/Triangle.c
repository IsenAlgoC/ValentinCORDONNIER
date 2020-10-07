//Exercice 4 cours Existence de triangle

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void main() {

	float AB;
	float AC;
	float BC;

	printf("Donner le premier nombre de AB\n");
	scanf_s("%f", &AB);
	printf("Donner le premier nombre de BC\n");
	scanf_s("%f", &BC);
	printf("Donner le premier nombre de CA\n");
	scanf_s("%f", &AC);

	if (AB < AC + BC && AC < BC + AB && BC < AC + AB && AB>=0 && AC>=0 && BC>=0) {
		printf("Le triangle existe\n");
	}
	else {
		printf("Le triangle n'existe pas\n");
	}
}