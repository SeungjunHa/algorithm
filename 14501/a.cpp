#include <cstdio>
#include <iostream>
#include <vector>

int N;
int elapsed[15];
int reward[15];

int arr[15];
int max;
void dfs(int depth, int cur)
{
	if(depth == N) {
		int sum = 0;
		for(int i=0;i<depth;i++) {
			if(arr[i]) {
				if(elapsed[i] + i <= N){
					sum += reward[i];
					i += elapsed[i]-1;
				}
			}
		}
		if(sum > max)
			max = sum;
		return;
	}
	arr[depth] = cur;
	if(depth < N) {
		for(int i=0;i<2;i++) {
			dfs(depth+1, i);
		}
	}
}
int main()
{
	scanf("%d\n", &N);
	for(int i=0;i<N;i++) 
		scanf("%d %d\n", &elapsed[i], &reward[i]);

	for(int i=0;i<2;i++) 
		dfs(0, i);
	
	printf("%d\n", max);
}

