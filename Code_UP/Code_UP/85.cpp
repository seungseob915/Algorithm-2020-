#include <stdio.h>

int main() {

	int h, b, c, s;
	double stor;
	scanf("%d %d %d %d", &h, &b, &c, &s);

	stor = double(h) * b * c * s / (1024 * 1024 * 8);
	printf("%.1lf MB", stor);

}
