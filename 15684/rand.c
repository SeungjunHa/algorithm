#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int N = 10;
	int H = 30;
	int M = (N-1)*H;
	printf("%d %d %d\n", N, M, H);
	for(int i=0;i<M;i++) {
		int a = (rand() % N) + 1;
		int b = (rand() % H) + 1;
		printf("%d %d\n", a, b);
	}
}
