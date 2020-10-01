#include <stdio.h>

int main() {

	int a[10000] = {}, n, r;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d ", &a[i]);
	}
	for (int r = n-1 ; r >= 0; r--) {
		printf("%d ", a[r]);
	}
}
