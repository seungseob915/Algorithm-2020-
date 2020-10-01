#include <stdio.h>

int main() {

	long int a, m, d, n, i, y;
	scanf("%ld %ld %ld %ld", &a, &m, &d, &n);

	y = a;

	for (i = 1; i < n; i++) {
		y = y * m +d;
	}
	printf("%ld", y);
}
