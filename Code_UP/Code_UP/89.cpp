#include <stdio.h>

int main() {

	int a, d, n, x, y;
	scanf("%d %d %d", &a, &d, &n);
	
	y = a;

	for (x = 1; x<n ; x++ ) {
		y = y + d;
	}
	printf("%d", y);
}
