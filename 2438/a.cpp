#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N;
int main(void)
{
	scanf("%d", &N);
	for(int i=0;i<N;i++) {
		for(int j=0;j<i+1;j++)
			printf("*");
		printf("\n");
	}
	return 0;
}
