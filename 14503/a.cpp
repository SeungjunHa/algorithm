#include <cstdio>
#include <vector>
#include <queue>

int N, M;
int map[50][50];
int visit[50][50];

void print_map(int cmap[50][50])
{
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++)
			printf("|%d|", map[i][j]);
		printf("\n");
	}
}
int drow[4] = { -1, 0, 1,  0 }; // 북 동 남 서
int dcol[4] = {  0, 1, 0, -1 }; // 북 동 남 서
int rd = 0;

int main()
{
	int row, col, d;
	scanf("%d %d\n", &N, &M);
	scanf("%d %d %d\n", &row, &col, &d);
	for(int i=0;i<N;i++) 
		for(int j=0;j<M;j++)
			scanf("%d ", &map[i][j]);

	visit[row][col] = 1;
	int stop;
	int dir;
	int go_flag;
	int result = 1;
	int crow, ccol;
	rd = d;
	while(1) {
		stop = 0;
		go_flag = 0;
		for(int i=0;i<4;i++) {
			rd = (rd + 3) % 4;
			crow = row + drow[rd];
			ccol = col + dcol[rd];
			if(map[crow][ccol] == 0 && 
					visit[crow][ccol] == 0) {
				row += drow[rd];
				col += dcol[rd];
				visit[row][col] = 1;
				go_flag = 1;
				break;
			}
		}
		if(go_flag) {
			result++;
			continue;
		}
		if(map[row-drow[rd]][col-dcol[rd]] == 1)
			break;
		row -= drow[rd];
		col -= dcol[rd];
	}
	printf("%d\n", result);
	//print_map(map);	
	return 0;
}
