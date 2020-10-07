#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void main() {
	unsigned long long numero = 1234567891234;
	int clef;
	unsigned long long tmp;
	unsigned long long tmp1;
	unsigned long long tmp2;
	unsigned long long tmp3;
	unsigned long long tmp4;

	//printf("Entrer le numero de securite sociale");
	//scanf_s("%lu", &numero);
	
	tmp = numero % 97;
	clef = 97 - tmp;
	
	tmp = numero / 1000000000000 ;

	numero = numero - (tmp * 1000000000000);

	tmp1 = numero / 10000000000;

	numero = numero - (tmp1 * 10000000000);

	tmp2 = numero / 100000000;

	numero = numero - (tmp2 * 100000000);

	tmp3 = numero / 1000000;

	numero = numero - (tmp3 * 1000000);

	tmp4 = numero / 1000;

	numero = numero - (tmp4 * 1000);

	printf("Clef %d\n", clef);

	//printf("%llu\n", tmp);
	//printf("%llu\n", tmp1);
	//printf("%llu\n", tmp2);
	//printf("%llu\n", tmp3);
	//printf("%llu\n", tmp4);
	system("pause");
}