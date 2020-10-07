#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void main() {

	srand(time(NULL));

	int MyTab1[100];
	int n;
	int* MyPtr = &MyTab1[0];
	for (int i = 0; i <= 99; i++) {

		MyTab1[i] = rand() % 21;
		printf("%d ", MyTab1[i]);

	}

	printf("\n");

	printf("Entrer la valeur recherchee \n");
	scanf_s("%d", &n);

	printf("la valeur a ete trouvee");

	for (int i = 0; i <= 99; i++) {
		MyPtr = &MyTab1[i];
		if (*MyPtr == n) {   //on met une "*" pour déréférencer la valeur qui est dans le pointeur
			printf(" en %d", i);
		}
	}


	printf("\n");
}