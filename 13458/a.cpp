#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>

int arr[1000000];
int boo[1000000];

int main()
{
	int N, B, C;
	unsigned long long result = 0;
	scanf("%d\n", &N);
	for(int i=0;i<N;i++)
		scanf("%d ", &arr[i]);
	scanf("%d %d\n", &B, &C);
	double CC = (double)C;
	result += N; // 총감독관 고사장마다 1명
	for(int i=0;i<N;i++) {
		arr[i] -= B;
		if(arr[i] < 0)
			arr[i] = 0;
	}

	for(int i=0;i<N;i++) 
		boo[i] = ceil(arr[i] / CC);
	
	for(int i=0;i<N;i++)
		result += boo[i];

	printf("%lld\n", result);	
	return 0;
}
