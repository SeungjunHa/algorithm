#include <stdio.h>

int v(int x)
{
	if(x<2)
		return 0;
	int a, b;
	a = v(x/2) + x%2 + 1;
	b = v(x/3) + x%3 + 1;
	printf("%d %d %d\n", a, b, x/2);
	return a > b ? b : a;
}
int main()
{
	int z;
	scanf("%d",&z);
	printf("%d", v(z));
}
