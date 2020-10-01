#include <stdio.h>

int main() {
	int i, s=0, n;
	scanf("%d", &n);

	for (i = 0; i <= n; i++)
	{
		if (s >= n) {
			break;
		}
		s = s + i;
	}
	printf("%d", i-1);
}