#include <stdio.h>

int main() {

	int a,b,c,n,m,l,count;
	scanf("%d %d %d", &a, &b, &c);
	count = 0;

	for (n = 0; n < a; n++) 
		for(m=0;m<b;m++)
			for(l=0;l<c;l++)
			{
				printf("%d %d %d\n", n, m, l);
				count = count + 1;
			}
	printf("%d", count);
}