//Exercice 3 cours revenu imposable

#include <stdlib.h>
#include <stdio.h>

void main() {

	int revenu = 0;
	float impotbrut = 0.0;

	printf("Donner votre revenu imposable\n");
	scanf_s("%d", &revenu);

	if (revenu <= 9700) {
		printf("revenu imposable a 0 pourcents\n");
	}

	if (9700 < revenu && revenu <=26971) {
		impotbrut = revenu * 0.14;
		printf("revenu imposable a 14 pourcents %f\n",impotbrut);
	}

	if (26971 < revenu && revenu <= 71826) {
		impotbrut = revenu * 0.3;
		printf("revenu imposable a 30 pourcents %f\n", impotbrut);
	}

	if (71826 < revenu && revenu <= 152108) {
		impotbrut = revenu * 0.41;
		printf("revenu imposable a 41 pourcents %f\n", impotbrut);
	}

	if (152108 < revenu) {
		impotbrut = revenu * 0.45;
		printf("revenu imposable a 45 pourcents %f\n", impotbrut);
	}
	system("pause");
}