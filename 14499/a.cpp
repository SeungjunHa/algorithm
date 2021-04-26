#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <queue>

int map[20][20];
int op[1000];
int N, M, x, y, K;

// x means row
// y means col
// 1,2,3,4 : 동 서 북 남
int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };

int dices[4][3];
int dices_index_x = 1;
int dices_index_y = 1;
void print_map()
{
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++)
			printf("|%d|", map[i][j]);
		printf("\n");
	}
	printf("Dices : \n");
	for(int i=0;i<4;i++) {
		for(int j=0;j<3;j++)
			printf("|%d|", dices[i][j]);
		printf("\n");
	}
}
void dice_control(int n)
{
	int temp;
	if(n == 2) {
		temp = dices[1][0];
		dices[1][0] = dices[1][1];
		dices[1][1] = dices[1][2];
		dices[1][2] = dices[3][1];
		dices[3][1] = temp;
	}
	if(n == 1) {
		temp = dices[1][2];
		dices[1][2] = dices[1][1];
		dices[1][1] = dices[1][0];
		dices[1][0] = dices[3][1];
		dices[3][1] = temp;
	}
	if(n == 4) {
		temp = dices[3][1];
		dices[3][1] = dices[2][1];
		dices[2][1] = dices[1][1];
		dices[1][1] = dices[0][1];
		dices[0][1] = temp;
	}
	if(n == 3) {
		temp = dices[0][1];
		dices[0][1] = dices[1][1];
		dices[1][1] = dices[2][1];
		dices[2][1] = dices[3][1];
		dices[3][1] = temp;
	}
}
#define PRINT 0
int main()
{
	scanf("%d %d %d %d %d\n", &N, &M, &x, &y, &K);
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			scanf("%d ", &map[i][j]);	
		}
	}
	for(int i=0;i<K;i++)
		scanf("%d ", &op[i]);

	for(int i=0;i<K;i++) {
		if(PRINT)
			printf("Time %d's op : %d\n", i, op[i]);
		x += dx[op[i]];
		y += dy[op[i]];
		if( (x < 0) || (x >= N) || (y < 0) || (y >= M) ) {
			x -= dx[op[i]];
			y -= dy[op[i]];
			//printf("Danger\n");
			continue;
		}
		dice_control(op[i]);
		int connect = dices[3][1];	
		if(map[x][y] == 0) {
			map[x][y] = connect;
		} else {
			dices[3][1] = map[x][y];
			map[x][y] = 0;
		}
		if(PRINT)
		printf("Time %d's (x, y) : (%d, %d)[%d]\n", i, x, y, dices[1][1]);	
		printf("%d\n", dices[1][1]);
		if(PRINT)
		print_map();
	}

	return 0;
}
