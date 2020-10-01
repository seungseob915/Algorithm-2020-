#include <stdio.h>

int main() {

	int a, b, c, day;
	scanf("%d %d %d", &a, &b, &c);

	for (day = 1; (day % a != 0) || (day % b != 0) || (day % c != 0); day++) {
	}
	printf("%d", day);
}
