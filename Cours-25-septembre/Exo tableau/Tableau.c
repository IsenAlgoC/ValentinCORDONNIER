#include<stdlib.h>
#include<stdio.h>

void main() {
	float MyTab[10][10] = { 0.0 };
	float val = 0;
	int i = 0;
	int j = 0;
	float tmp = 1;
	int tmp1;
	int tmp2;
	float moyenne = 0;
	int n = 0;

	while (val >= 0) {
		printf("Entrer une valeur\n");
		scanf_s("%f", &val);
		if (val >= 0) {
			MyTab[i][j] = val;
			i = i + 1;
		}
		if (i == 10) {
			i = 0;
			j = j+1;
		}
	}

	i = -1;
	j = 0;

	while (i!=9 && j!=10) {
		i = i + 1;
		printf("%.2f  ", MyTab[i][j]);
		if (i == 9) {
			i = -1;
			j = j + 1;
			printf("\n");
		}
	}

	//system("pause");

	//insérer une valeur à l'endroit demander

	while (val >= 0) {
		printf("Entrer une valeur\n");
		scanf_s("%f", &val);
		if (val >= 0) {
			printf("Pour quelle ligne ?\n");
			scanf_s("%d", &tmp1);
			j = tmp1 - 1;
			printf("Pour quelle colonne ?\n");
			scanf_s("%d", &tmp2);
			i = tmp2 - 1;
			MyTab[i][j] = val;
		}
	}

	i = -1;
	j = 0;

	while (i != 9 && j != 10) {
		i = i + 1;
		printf("%.2f  ", MyTab[i][j]);
		if (i == 9) {
			i = -1;
			j = j + 1;
			printf("\n");
		}
	}
	system("pause");

	val = 0;

	while (val >= 0) {
		printf("Entrer une valeur negative pour arreter\n");
		scanf_s("%f", &val);
		if (val >= 0) {
			printf("Pour quelle ligne ?\n");
			scanf_s("%d", &tmp1);
			j = tmp1 - 1;
			printf("Pour quelle colonne ?\n");
			scanf_s("%d", &tmp2);
			i = tmp2 - 1;
			MyTab[i][j] = 0;
		}
	}

	i = -1;
	j = 0;

	while (i != 9 && j != 10) {
		i = i + 1;
		printf("%.2f  ", MyTab[i][j]);
		if (i == 9) {
			i = -1;
			j = j + 1;
			printf("\n");
		}
	}

	system("pause");

	//Calcul de la moyenne

	i = -1;
	j = 0;

	while (i != 9 && j != 10) {
		if (i == 9) {
			i = -1;
			j = j + 1;
			printf("\n");
		}
		i = i + 1;
		moyenne = moyenne + MyTab[i][j];
		n = n+1;
	}

	moyenne = moyenne / 100;

	printf("la valeur de la moyenne est %f\n", moyenne);
	
	system("pause");
}