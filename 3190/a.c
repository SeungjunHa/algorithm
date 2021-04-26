#include <stdio.h>

int N, K, L;
int map[102][102];
typedef struct snake {
	int row[20000];
	int col[20000];
	int dir;
}SNAKE;
SNAKE snake;

// 0 : 오른쪽 / 1 : 위쪽 / 2 : 왼쪽 / 3 : 아래쪽
typedef struct direction {
	int row;
	int col;
}DIRECTION;
DIRECTION dir[4];

typedef struct move_info {
	int time;
	char pos;
}MOVE_INFO;
MOVE_INFO mi[10000];

void print_map(int time)
{
	printf("Time %d map : \n", time);
	for(int i=0;i<N+2;i++) {
		for(int j=0;j<N+2;j++) 
			printf("|%d|", map[i][j]);
		printf("\n");
	}
}

void init_direction()
{
	dir[0].row =  0; dir[0].col =  1;
	dir[1].row = -1; dir[1].col =  0;
	dir[2].row =  0; dir[2].col = -1;
	dir[3].row =  1; dir[3].col =  0;
}
int main()
{
	scanf("%d\n", &N);
	scanf("%d\n", &K);
	for(int i=0;i<K;i++) {
		int a,b;
		scanf("%d %d\n", &a, &b);
		map[a][b] = 1;
	}
	for(int i=0;i<N+2;i++) {
		map[0][i] = 2;
		map[i][0] = 2;
		map[N+1][i] = 2;
		map[i][N+1] = 2;
	}
	scanf("%d\n", &L);
	for(int i=0;i<L;i++) {
		int a; char b;
		scanf("%d %c\n", &a, &b);
		mi[a].time = 1;
		mi[a].pos = b;		
	}
	init_direction();
	
	// 0 : 오른쪽 / 1 : 위쪽 / 2 : 왼쪽 / 3 : 아래쪽
	int time = 0;
	int success = 0;
	int head_row, head_col, tail = 0;
	int a;
	snake.row[time] = 1;
	snake.col[time] = 1;
	snake.dir = 0;
	map[snake.row[time]][snake.col[time]] = 3;

	while(1) {
		head_row = snake.row[time] + dir[snake.dir].row;
		head_col = snake.col[time] + dir[snake.dir].col;
		time++;
		//printf("%d snake head : %d %d / %d\n", time, head_col, head_row, snake.dir);

		if(map[head_row][head_col] == 2 || map[head_row][head_col] == 3)
			break;

		if(map[head_row][head_col] != 1)  {
			map[snake.row[tail]][snake.col[tail]] = 0;
			tail++;
		}
		map[head_row][head_col] = 3;
		snake.row[time] = head_row;
		snake.col[time] = head_col;
		
		//print_map(time);	
		if(mi[time].time) {
			if(mi[time].pos == 'D')	
				snake.dir = (snake.dir + 3) % 4;	
			else
				snake.dir = (snake.dir + 1) % 4;
		}
	}
	printf("%d\n", time);
	return 0;
}




