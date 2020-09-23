#include <stdlib.h>
#include<stdio.h>

int main() {
	float longueur = 0;
	float largeur = 0;
	float hauteur = 0;
	float tmp = 0;
	int i = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	printf("Les dimensions du bagage doivent etre entre 1 et 150cm \n");
	printf("Donner la longueur du bagage en cm \n");
	scanf_s("%f", &longueur);
	printf("Donner la largeur du bagage en cm \n");
	scanf_s("%f", &largeur);
	printf("Donner la hauteur du bagage en cm \n");
	scanf_s("%f", &hauteur);

	if (longueur < largeur) {
		tmp = longueur;
		longueur = largeur;
		largeur = tmp;
	}

	if (largeur < hauteur) {
		tmp = largeur;
		largeur = hauteur;
		hauteur = tmp;
	}

	if (longueur < largeur) {
		tmp = longueur;
		longueur = largeur;
		largeur = tmp;
	}

	while (i != 3) {
		if (longueur >= 1 && longueur <= 150) {
			if (longueur > 55) {
				printf("NON VALIDE");
				i = 3;
			}
			else {
				a = 1;
			}
		}
		else {
			i=0;
			printf("Donner la longueur du bagage en cm \n");
			scanf_s("%f", &longueur);
		}
		if (largeur >= 1 && largeur <= 150) {
			if (largeur > 35) {
				printf("NON VALIDE");
				i = 3;
			}
			else {
				b = 1;
			}
		}
		else {
			i = 0;
			printf("Donner la largeur du bagage en cm \n");
			scanf_s("%f", &largeur);
		}
		if (hauteur >= 1 && hauteur <= 150) {
			if (hauteur > 25) {
				printf("NON VALIDE");
				i = 3;
			}
			else {
				c = 1;
			}
		}	
		else {
			i = 0;
			printf("Donner la longueur du bagage en cm \n");
			scanf_s("%f", &hauteur);
		}
		if ( a == 1 && b == 1 && c == 1 ) {
			printf("VALIDE\n");
			i = 3;
		}
	}
	system("pause");

}