#include <stdio.h>

int main() {

	int i, n;

	scanf("%x", &i);

	for (n = 1; n < 16; n++) {
		printf("%X*%X=%X\n", i, n, i * n);
	}
}