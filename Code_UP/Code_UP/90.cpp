#include <stdio.h>

int main() {

	long int a, r, n, x, y;
	scanf("%d %d %d", &a, &r, &n);

	y = a;

	for (x = 1; x < n; x++) {
		y = y * r;
	}
	printf("%ld", y);
}
