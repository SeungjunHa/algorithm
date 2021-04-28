#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define likely(x) __builtin_expect((x), 1)
#define unlikely(x) __builtin_expect((x), 0)

int N, K;
int main(void)
{
	scanf("%d %d", &N, &K);
	int cnt = 0;
	for(int i=1;i<=N;i++) {
		if(N % i == 0) {
			K--;
			if(!K) {
				printf("%d\n", i); 
				break;
			}
		}
		if(unlikely(i == N/2))
			i = N-1;
	}
	if(K)
		printf("0\n");
	return 0;
}
