#include <stdio.h>

int main() {

	int a[23] = {}, r, n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d ", &r);
		a[r - 1] = a[r - 1] + 1;
	}
	for (r = 0; r < 23; r++) {
		printf("%d ", a[r]);
	}
}
