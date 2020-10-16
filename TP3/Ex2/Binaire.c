#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void main() {

	unsigned int val = 2868838400;
	int bits = 8;
	int octets = 1;

	while (val > pow(2,bits) - 1) {
		bits = bits + 1;
		if (bits % 8 == 0) {
			octets = octets + 1;
		}
	}

	printf(" Le nombre d'octets est de %d\n", octets);
	printf(" Le nombre de bits est de %d\n", bits);

	for (int i = 0; i <= 31; i++) {
		if (val% 2 == 1) {
			printf("bit %d : ON\n", i);
		}
		else {
			printf("bit %d : OFF\n", i);
		}
		val = val >> 1;
	}
	printf("\nBye!");
}