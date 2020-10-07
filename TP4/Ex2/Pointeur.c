#include <stdlib.h>
#include <stdio.h>

#define SEPARATEUR '/'
#define TAILLETAB1 20

void main() {

	int MyTab1[TAILLETAB1];

	for (int i = 1; i<=20 ; i++) {
		MyTab1[i - 1] = i;
	}

	for (int j = 0; j <= 19; j++) {
		printf("%d/", MyTab1[j]);
	}

	printf("\n\n");

	int* MyPtr = &MyTab1[19];

	//Utilisation des pointeurs pour inverser l'ordre des valeurs dans le tableau

	for (int i = 1; i <= 20; i++) {

		printf("%d/", MyTab1[20 - i]);

		*MyPtr = MyTab1[i - 1];

		MyPtr = &MyTab1[20 - i];
		
	}


	printf("\n");
	system("pause");
}