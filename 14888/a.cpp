#include <cstdio>
#include <vector>
#include <queue>

int N;
long long arr[11];
int op_arr[4];
int temp_arr[10];
long long max = -1000000001;
long long min = 1000000001;
void dfs(int depth, int r)
{
	if(depth == N-1) {
		long long sum = arr[0];
		for(int i=0;i<depth;i++) {
			if(temp_arr[i] == 0)
				sum = sum + arr[i+1];
			if(temp_arr[i] == 1)
				sum = sum - arr[i+1];
			if(temp_arr[i] == 2)
				sum *= arr[i+1];
			if(temp_arr[i] == 3)
				sum = (long long)(sum/arr[i+1]);
		}
		if(sum > max)
			max = sum;
		if(sum < min)
			min = sum;
		return;
	}
	for(int i=0;i<4;i++) {
		if(op_arr[i] == 0)
			continue;
		temp_arr[depth] = i;
		op_arr[i]--;
		dfs(depth+1, i+1);
		op_arr[i]++;
	}
}
int main()
{
	scanf("%d", &N);
	for(int i=0;i<N;i++)
		scanf("%lld", &arr[i]);
	for(int i=0;i<4;i++)
		scanf("%d", &op_arr[i]);
	dfs(0, 0);
	printf("%lld\n%lld\n", max, min);
	return 0;
}
