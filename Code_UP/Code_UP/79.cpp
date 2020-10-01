#include <stdio.h>

int main() {
	char x;
	do{
		scanf("%c", &x);
		printf("%c", x);
	} while (x != 'q');
}