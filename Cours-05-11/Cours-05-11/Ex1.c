
#include <stdlib.h>
#include <stdio.h>

int MyStrlen(char* mot) {

	int StrSize=0;
	int tmp=mot[0];

	while (*mot != '\0') {
		mot++;
		StrSize++;
	}

	return StrSize;
}

void main() {
	int x;

	char mot[10] = {'J','O','H','N','\0'};
	x=MyStrlen(mot);

	printf("%d\n", x);
}