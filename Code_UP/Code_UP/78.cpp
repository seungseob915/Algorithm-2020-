#include <stdio.h>

int main() {
	int x, t = 0, s=0;
	scanf("%d", &x);

	while (t <= x) {
		if (t % 2 == 0) {
			s = s + t;
			t++;
		}
		else
			t++;
	}
	printf("%d", s);
}