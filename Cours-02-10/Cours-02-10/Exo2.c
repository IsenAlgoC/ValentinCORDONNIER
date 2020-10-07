#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void main() {

	int MyTab[10][10] = { 0 };
	int i = -1;
	int j = 0;
	int n = 0;

	srand((unsigned)time(NULL));

	while (i != 9 && j != 10) {
		i = i + 1;

		int val = rand() % 20 +1;

		MyTab[i][j] = val;

		if (i == 9) {
			i = -1;
			j = j + 1;
		}
	}

	i = -1;
	j = 0;

	while (i != 9 && j != 10) {
		i = i + 1;
		printf("%d  ", MyTab[i][j]);
		if (i == 9) {
			i = -1;
			j = j + 1;
			printf("\n");
		}
	}

	system("pause");

	printf("\n\n");

	int MyTab1[10][10];
	i = -1;
	j = 0;

	while (i != 9 && j != 10) {
		i = i + 1;
		MyTab1[i][j] = MyTab[j][i];

		if (i == 9) {
			i = -1;
			j = j + 1;
		}
	}

	i = -1;
	j = 0;

	while (i != 9 && j != 10) {
		i = i + 1;
		printf("%d  ", MyTab1[i][j]);
		if (i == 9) {
			i = -1;
			j = j + 1;
			printf("\n");
		}
	}

	system("pause");


}