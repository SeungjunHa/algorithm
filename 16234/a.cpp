#include <cstdio>

int N, L, R;

int map[50][50];
int open[50][50];
int visit[50][50];

// 동 북 서 남
int drow[4] = { 0, -1, 0, 1 };
int dcol[4] = { 1, 0, -1, 0 };

#define abs(a, b) ((a > b) ? (a - b) : (b - a))

void print_map()
{
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) 
			printf("%d ", map[i][j]);
		printf("\n");
	}
}
bool simulation()
{
	int nrow, ncol;
	for(int i=0;i<N;i++) 
		for(int j=0;j<N;j++) {
			visit[i][j] = 0;
			open[i][j] = 0;
		}
	int sum = 0;
	int cnt = 0;
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			for(int k=0;k<4;k++) {
				nrow = i+drow[k];
				ncol = j+dcol[k];
				if(nrow < 0 || nrow >= N || ncol < 0 || ncol >= N)
					continue;
				int diff = abs(map[i][j], map[nrow][ncol]);
				if(L <= diff && diff <= R) { 
					if(!visit[i][j]) {
						open[i][j] = 1;
						visit[i][j] = 1;
						cnt++;
					}
					if(!visit[nrow][ncol]) {
						open[nrow][ncol] = 1;
						visit[nrow][ncol] = 1;
						cnt++;
					}
				}
			}
		}
	}
	if(cnt) {
		while(cnt) {		
			for(int i=0;i<N;i++) 
				for(int j=0;j<N;j++) 
					if(open[i][j] == 1) 
						map[i][j] = div;
			
		}
	}
	return cnt == 0 ? false : true;
}
int main()
{
	scanf("%d %d %d", &N, &L, &R);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++) {
			scanf("%d ", &map[i][j]);
		}
	int result = 0;
	while(1) {
		if(!simulation())
			break;
		result++;
		print_map();
	}
	printf("%d\n", result);
	return 0;
}

