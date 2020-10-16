#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

#define NBMAXNOTES 30
void main() {

	int note;
	int MyTab[NBMAXNOTES] = { -2 };
	char lettre;
	int absent = 0;
	int nbcor = 0;
	int tailleTab;
	int valmax = 0;
	int valmin = 20;
	float moyenne = 0;
	double ecartype = 0;
	double valinter = 0;

	for (int i = 0; i <= 29; i++) {
		
		printf("Entrer la note no %d\n", i+1);
		scanf_s("%d", &note);

		tailleTab = i;

		if (note >= 0 && note <= 20) {
			MyTab[i] = note;
			nbcor++;

			if (valmax < note) {
				valmax = note;
			}
			if (valmin > note) {
				valmin = note;
			}
			moyenne = moyenne + note;
		}
		else {
			printf("Eleve absent ? Ou voulez-vous arreter la saisie des notes ?\n");
			lettre = _getch();
			switch (lettre) {
			case 'A':
				printf("Eleve absent\n");
				absent++;
				MyTab[i] = -1;

			case 'O':
				i=30;
				break; // break obligatoire sinon le switch va tester MyTab[30] qui n'existe pas

			case 'N':
				printf("Entrer la note no %d\n", i + 1);
				scanf_s("%d", &note);
				MyTab[i] = note;
				nbcor++;
				if (valmax < note) {
					valmax = note;
				}
				if (valmin > note) {
					valmin = note;
				}
				moyenne = moyenne + note;
			}
		}
	}
	moyenne = moyenne / (double)nbcor;

	for (int i = 0; i <= tailleTab; i++) {
		if (MyTab[i]>0){
			valinter = valinter + ((valinter - moyenne)*(valinter - moyenne));
		}
	}

	ecartype = sqrt((double)(1 / nbcor - 1) * valinter);
	
	printf("Le nombre d eleve absent est de %d\n", absent);
	printf("Le nombre de note correcte est de %d\n", nbcor);
	printf("La note maximale est %d\n", valmax);
	printf("La note minimale est %d\n", valmin);
	printf("La valeur de la moyenne est %f\n", moyenne);
	printf("La valeur de l ecart type est %2.f\n", ecartype);
}