#include <stdlib.h>
#include <stdio.h>

void main() {

	int taille;
	int nb_mots = 0;
	float moyenne_longueur = 0;
	char phrase[1024];
	int j = 0;
	printf("Entrer une phrase\n");
	fgets(phrase, 1024, stdin); //ne pas oublier de mettre un espace à la fin sinon le programme oubliera le dernier mot

	taille = strlen(phrase);

	//printf("%d\n", taille);

	for (int i = 0; i <= (taille - 2); i++) {
		if (phrase[i] == ' ') {
			nb_mots = nb_mots + 1;
			//printf("%d\n", j);
			moyenne_longueur = moyenne_longueur + j;
			j = 0;
		}
		else {
			j = j + 1;
		}
	}
	moyenne_longueur = moyenne_longueur / nb_mots;

	printf("Le nombre de mots est de %d\n", nb_mots);
	printf("La moyenne de longueur de mot est de %f\n", moyenne_longueur);
}