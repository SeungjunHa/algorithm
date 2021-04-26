#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K;
vector<vector<int>> map(300, vector<int>(300, 0));

int main(void)
{
	scanf("%d %d", &N, &M);
	for(int i=0;i<N;i++) 
		for(int j=0;j<M;j++) 
			scanf("%d", &map[i][j]);
		
	scanf("%d", &K);
	for(int i=0;i<K;i++) {
		int s_r, s_c, e_r, e_c, sum = 0;
		scanf("%d %d %d %d", &s_r, &s_c, &e_r, &e_c);
		s_r--; s_c--;
		for(int j=s_r;j<e_r;j++) 
			for(int k=s_c;k<e_c;k++) 
				sum += map[j][k];
			
		printf("%d\n", sum);
	}
	return 0;
}
