#include <cstdio>
#include <vector>
#include <queue>
int N, M, H;

int map[300][2];
int line_map[300][10];
// 사다리 row 갯수 < H
// 사다리 col 갯수 < N-1
int min = 4;
bool possible = false;

#define MAX 3
void print_line_map(int smap[300][10])
{
	for(int i=0;i<H;i++) {
		for(int j=0;j<N-1;j++) 
			printf("%d ", smap[i][j]);
		printf("\n");
	}
}
bool simulation()
{
	int going;
	int start[10];
	int finish[10];
	bool is_same = true;
	for(int i=0;i<N;i++) {
		start[i] = i;
		going = i;
		for(int j=0;j<H;j++) {
			if(going == 0) {
				if(line_map[j][going]) {
					going += 1;
				}
			} else if(going == N-1) {
				if(line_map[j][going-1]) {
					going -= 1;
				}
			} else {
				if(line_map[j][going]) 
					going += 1;
				else if(line_map[j][going-1]) 
					going -= 1; 	
			}
		}
		finish[i] = going;
		if(start[i] != finish[i]) {
			is_same = false;
			break;
		}
	}
	return is_same;
}

void dfs(int depth, int row, int skip, int limit)
{
	if(depth == limit) {
		//printf("Current map[%d] : \n", depth);
		//print_line_map(line_map);
		if(simulation()) {
			possible = true;
			if(depth < min)
				min = depth;
		}
		return;
	}
	for(int i=row;i<H;i++) {
		for(int j=0;j<N-1;j++) {
			if(possible) 
				break;
			if(i*N+j < skip)
				continue;
			if(line_map[i][j] == 1)
				continue;
			if(j == 0) {
				if(line_map[i][1] == 0) {
					line_map[i][j] = 1;
					dfs(depth+1, i, i*N+j+1, limit);
					line_map[i][j] = 0;
				}
			} else if(j == N-2) {
				if(line_map[i][N-3] == 0) {
					line_map[i][j] = 1;
					dfs(depth+1, i, i*N+j+1, limit);
					line_map[i][j] = 0;
				}
			} else {
				if(line_map[i][j-1] == 0 && line_map[i][j+1] == 0) {
					line_map[i][j] = 1;
					dfs(depth+1, i, i*N+j+1, limit);
					line_map[i][j] = 0;
				}
			}
		}
		if(possible)
			break;
	}
}
int main()
{
	scanf("%d %d %d", &N, &M, &H);
	for(int i=0;i<M;i++) {
		scanf("%d %d", &map[i][0], &map[i][1]);
		line_map[map[i][0]-1][map[i][1]-1] = 1;
	}

	//printf("Initial Line Map : \n");
	//print_line_map(line_map);
	for(int i=0;i<4;i++) {
		dfs(0, 0, 0, i);
		if(possible)
			break;
	}
	if(possible)
		printf("%d\n", min);
	else 
		printf("-1\n");
	return 0;
}
