#include <stdio.h>

int main() {

	int a[10000] = {}, n, min=100000;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d ", &a[i]);
		if (min > a[i])
			min = a[i];
	}
	printf("%d", min);
}
