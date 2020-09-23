#include <stdlib.h>
#include<stdio.h>

int main() {
	unsigned short int resultat = 0;
	unsigned short int resultat1 = 0;
	unsigned short int resultat2 = 0;


	//Somme des n premiers entiers positifs:

	int i = 1;

	for (i = 1; i <= 100; i++) {
		resultat = resultat + i;
	}

	int j = 0;

	while (j != 100) {
		j = j + 1;
		resultat1 = resultat1 + j;
	}

	int k = 0;

	do {
		k = k + 1;
		resultat2 = resultat2 + k;
	} while (k != 100);

	printf("Le resultat obtenu avec la boucle for est %d\n", resultat);
	
	printf("Le resultat obtenu avec la boucle while est %d\n", resultat1);
	
	printf("Le resultat obtenu avec la boucle do est %d\n", resultat2);
	
	//Trouver la valeur maximum de n sans dépassement de capacité :

	int SommeNMoinsUn = 0;
	unsigned short int resultat3 = 0;
	int n = 0;

	while (resultat3 >= SommeNMoinsUn) {
		SommeNMoinsUn = resultat3;
		n = n + 1;
		resultat3 = resultat3 + n;
	}

	//Avec cette boucle while, on regarde le moment où la somme de rang n devient plus petite que celle de rang n-1, on a alors la certitude qu'il y a
	//un phénomène de dépassement car tous les nombres sont positifs (de plus on prend n-1 en valeur max, car en n il y a le dépassement)

	printf("La valeur maximum de n est %d\n", n-1);
	
	//Conception du test en sachant que la valeur max de la somme est 65535

	int n1 = 0;
	int somme1 = 0;

	while (65535 - somme1 > n1) {
		n1 = n1 + 1;
		somme1 = somme1 + n1;
	}
	
	printf("Le resultat obtenu avec le test de condition est %d\n", somme1);

	//Demander la valeur de n à l’utilisateur:


	int m=0;
	int l=0;
	unsigned short int resultat4 = 0;

	scanf_s("%hu", &l);

	for (m = 1; m <= l; m++) {
		resultat4 = resultat4 + m;
	}

	printf("Le resultat obtenu avec la boucle est %d\n", resultat4);

	//La somme devient une valeur plus basse qu'elle ne devrait l'être quand on utilise un n trop grand

	//Recommencer tant que n est trop grand:

	int b = 0;
	int v = 0;
	unsigned short int resultat5 = 0;

	printf("Entrer une valeur de n\n");
	scanf_s("%hu", &v);

	for (b = 0; b <= v; b++) {
		if (65535 - resultat5 > b) {
			resultat5 = resultat5 + b;
		}
		else {
			resultat5 = 0;
			b = 0;
			printf("Entrer une valeur de n\n");
			scanf_s("%hu", &v);
		}
	}

	printf("Le resultat obtenu avec la boucle est %d\n", resultat5);

	system("pause");


}