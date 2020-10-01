#include <stdio.h>

int main() {

	int i, n, sum;
	scanf("%d", &i);

	for (n = 1; n <= i; n++) {
		sum += n;
		if (sum >= i) {
			break;
		}
	}
	printf("%d", sum);

}
