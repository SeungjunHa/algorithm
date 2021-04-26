#include <cstdio>
#include <vector>
#include <queue>

int N, L;
int map[100][100];
int symmetry_map[100][100];

#define abs(a, b) a > b ? a - b : b - a
int func(int arr[100])
{
	int possible = 1;
	int slove[100];
	for(int i=0;i<N;i++)
		slove[i] = 0;
	/*printf("Array : ");
	for(int i=0;i<N;i++)
		printf("%d ", arr[i]);
	printf("\n");*/
	for(int i=0;i<N-1;i++) {
		if(arr[i] == arr[i+1])
			continue;
		int diff = abs(arr[i], arr[i+1]);
		if(diff > 1) {
			possible = 0;
			break;
		}
		if(arr[i] > arr[i+1]) {
			if(i+L >= N) {
				possible = 0;
				break;
			}
			int pivot = arr[i]-1;
			for(int j=i+1;j<=i+L;j++) {
				if(arr[j] != pivot || slove[j] == 1) {
					possible = 0;
					break;
				}
			}
			if(possible == 0)
				break;
			for(int j=i+1;j<=i+L;j++) 
				slove[j] = 1;
		} else {
			if(i+1 < L) {
				possible = 0;
				break;
			}
			int pivot = arr[i];
			for(int j=i;j>=i-L+1;j--) {
				if(arr[j] != pivot || slove[j] == 1) {
					possible = 0;
					break;
				}
			}
			if(possible == 0)
				break;
			for(int j=i;j>=i-L+1;j--) 
				slove[j] = 1;
		}
	}

	return possible;
}
int main()
{
	scanf("%d %d", &N, &L);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++) {
			scanf("%d", &map[i][j]);
			symmetry_map[j][i] = map[i][j];
		}
		
	int sum = 0;
	for(int i=0;i<N;i++) {
		sum += func(map[i]);			
		sum += func(symmetry_map[i]);
	}
	printf("%d\n", sum);
}
