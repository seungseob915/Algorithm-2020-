#include <stdio.h>

int main() {

	int i, n;
	scanf("%x", &i);

	for (n = 1; n <= i; n++) {
		if((n%3)==0)
			printf("X ");
		else {
			printf("%d ", n);
		}
	}
}