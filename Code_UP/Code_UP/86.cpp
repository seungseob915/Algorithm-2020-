#include <stdio.h>

int main() {

	unsigned int h, b, w;
	double stor;
	scanf("%d %d %d", &h, &b, &w);

	stor = double(h * b * w) / (1024 * 1024 * 8);
	printf("%.2lf MB", stor);

}
