#include <stdlib.h>
#include <stdio.h>

void main() {

	char mot[30];
	char motbis[30] = { 0 };
	char tmp[30];
	int taille;

	printf("Veuillez entrer un mot \n");
	fgets(mot, 30, stdin);

	taille = strlen(mot);

	printf("taille du mot %d\n", taille);

	int i = 0;

	while (i <= taille/2) {
		if (mot[i] == mot[taille-(i+2)]) {
			i = i + 1;
		}
		else {
			printf("le mot n'est pas un palindrome\n");
			break;
		}
	}

	if (i >= taille/2) {
		printf("le mot est un palindrome\n");
	}
	
	system("pause");
}