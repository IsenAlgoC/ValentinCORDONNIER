#include <stdlib.h>
#include <stdio.h>

void main() {
	char prenom[20] = { 0 };
	char nom[20] = { 0 };
	char sexe[20] = { 0 };

	printf("Veuillez entrer un nom \n");
	fgets(nom, 20, stdin);

	printf("Veuillez entrer un prenom \n");
	fgets(prenom, 20, stdin);
	
	printf("Veuillez entrer un sexe avec H ou F \n");


	if ( getch()=='H') {
		strcpy(sexe, "Monsieur");
	}
	else {
		strcpy(sexe, "Madame");
	}

	printf("%s %s %s \n", sexe, prenom, nom);

	system("pause");
}