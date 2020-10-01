#include <stdio.h>

int main() {

	int i,n;
	scanf("%d", &i);

	for (n = 1; n <= i; n++) {
		if (n%3 != 0)  {
			printf("%d ", n);
		}	
	}
}
