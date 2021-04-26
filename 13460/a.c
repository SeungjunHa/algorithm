#include <stdio.h>

#define MAX 10

int map[MAX][MAX];
int N, M;

typedef struct pos {
	int row;
	int col;
}POS;

POS blue, red, end;

void print_map()
{
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) 
			printf("%d", map[i][j]);
		printf("\n");
	}
}

void move_red_ball(int row, int col, int type)
{
	int i;
	if(type == 1) {
		for(i=col;i<M-1;i++) {
			if(map[row][i+1] == 1) {
				red.col++;
				if(map[row][i] == 5)
					map[row][i] = 4;
				else
					map[row][i] = 1;
				map[row][i+1] = 2;
			} else if(map[row][i+1] == 4 || map[row][i+1] == 6) {
				red.col++;
				map[row][i] = 1;
				map[row][i+1] = 5;
				break;
			} else
				break;
		}
	}
	if(type == 2) {
		for(i=row;i>0;i--) {
			if(map[i-1][col] == 1) {
				red.row--;
				if(map[i][col] == 5)
					map[i][col] = 4;
				else
					map[i][col] = 1;
				map[i-1][col] = 2;
			} else if(map[i-1][col] == 4 || map[i-1][col] == 6) {
				red.row--;
				map[i][col] = 1;
				map[i-1][col] = 5;
				break;
			} else
				break;
		}
	}
	if(type == 3) {
		for(i=col;i>0;i--) {
			if(map[row][i-1] == 1) {
				red.col--;
				if(map[row][i] == 5)
					map[row][i] = 4;
				else
					map[row][i] = 1;
				map[row][i-1] = 2;
			} else if(map[row][i-1] == 4 || map[row][i-1] == 6) {
				red.col--;
				map[row][i] = 1;
				map[row][i-1] = 5;
				break;
			} else
				break;
		}
	}
	if(type == 4) {
		for(i=row;i<N-1;i++) {
			if(map[i+1][col] == 1) {
				red.row++;
				if(map[i][col] == 5)
					map[i][col] = 4;
				else
					map[i][col] = 1;
				map[i+1][col] = 2;
			} else if(map[i+1][col] == 4 || map[i+1][col] == 6) {
				red.row++;
				map[i][col] = 1;
				map[i+1][col] = 5;
				break;
			} else
				break;
		}
	}
}
void move_blue_ball(int row, int col, int type)
{
	int i;
	if(type == 1) {
		for(i=col;i<M-1;i++) {
			if(map[row][i+1] == 1) {
				blue.col++;
				if(map[row][i] == 6)
					map[row][i] = 4;
				else
					map[row][i] = 1;
				map[row][i+1] = 3;
			} else if(map[row][i+1] == 4 || map[row][i+1] == 5) {
				blue.col++;
				map[row][i] = 1;
				map[row][i+1] = 6;
				break;
			} else
				break;
		}
	}
	if(type == 2) {
		for(i=row;i>0;i--) {
			if(map[i-1][col] == 1) {
				blue.row--;
				if(map[i][col] == 6)
					map[i][col] = 4;
				else
					map[i][col] = 1;
				map[i-1][col] = 3;
			} else if(map[i-1][col] == 4 || map[i-1][col] == 5) {
				blue.row--;
				map[i][col] = 1;
				map[i-1][col] = 6;
				break;
			} else
				break;
		}
	}
	if(type == 3) {
		for(i=col;i>0;i--) {
			if(map[row][i-1] == 1) {
				blue.col--;
				if(map[row][i] == 6)
					map[row][i] = 4;
				else
					map[row][i] = 1;
				map[row][i-1] = 3;
			} else if(map[row][i-1] == 4 || map[row][i-1] == 5) {
				blue.col--;
				map[row][i] = 1;
				map[row][i-1] = 6;
				break;
			} else
				break;
		}
	}
	if(type == 4) {
		for(i=row;i<N-1;i++) {
			if(map[i+1][col] == 1) {
				blue.row++;
				if(map[i][col] == 6)
					map[i][col] = 4;
				else
					map[i][col] = 1;
				map[i+1][col] = 3;
			} else if(map[i+1][col] == 4 || map[i+1][col] == 5) {
				blue.row++;
				map[i][col] = 1;
				map[i+1][col] = 6;
				break;
			} else
				break;
		}
	}
}

void go_right()
{
	int col;
	int row = blue.row;
	int i;
	// blue red가 같은 행에 있으면 누구부터 움직일지 체크해야함
	if(red.row == blue.row) {
		// blue부터 움직임
		if(red.col < blue.col) {
			move_blue_ball(blue.row, blue.col, 1);
			move_red_ball(red.row, red.col, 1);
		} else {
		// red부터 움직임
			move_red_ball(red.row, red.col, 1);
			move_blue_ball(blue.row, blue.col, 1);
		}
	} else {
		// blue 따로 red 따로 움직여도 됨
		move_red_ball(red.row, red.col, 1);
		move_blue_ball(blue.row, blue.col, 1);
	}
}

void go_top()
{
	int row;
	int col = blue.col;
	int i;
	// blue red가 같은 행에 있으면 누구부터 움직일지 체크해야함
	if(red.col == blue.col) {
		// blue부터 움직임
		if(red.row > blue.row) {
			move_blue_ball(blue.row, blue.col, 2);
			move_red_ball(red.row, red.col, 2);
		} else {
		// red부터 움직임
			move_red_ball(red.row, red.col, 2);
			move_blue_ball(blue.row, blue.col, 2);
		}
	} else {
		// blue 따로 red 따로 움직여도 됨
		move_red_ball(red.row, red.col, 2);
		move_blue_ball(blue.row, blue.col, 2);
	}
}
void go_left()
{	
	int row = blue.row;
	int col;
	int i;
	// blue red가 같은 행에 있으면 누구부터 움직일지 체크해야함
	if(red.row == blue.row) {
		// blue부터 움직임
		if(red.col > blue.col) {
			move_blue_ball(blue.row, blue.col, 3);
			move_red_ball(red.row, red.col, 3);
		} else {
		// red부터 움직임
			move_red_ball(red.row, red.col, 3);
			move_blue_ball(blue.row, blue.col, 3);
		}
	} else {
		// blue 따로 red 따로 움직여도 됨
		move_red_ball(red.row, red.col, 3);
		move_blue_ball(blue.row, blue.col, 3);
	}

}
void go_bottom()
{
	int row;
	int col = blue.col;
	int i;
	// blue red가 같은 행에 있으면 누구부터 움직일지 체크해야함
	if(red.col == blue.col) {
		// blue부터 움직임
		if(red.row < blue.row) {
			move_blue_ball(blue.row, blue.col, 4);
			move_red_ball(red.row, red.col, 4);
		} else {
		// red부터 움직임
			move_red_ball(red.row, red.col, 4);
			move_blue_ball(blue.row, blue.col, 4);
		}
	} else {
		// blue 따로 red 따로 움직여도 됨
		move_red_ball(red.row, red.col, 4);
		move_blue_ball(blue.row, blue.col, 4);
	}
}
void move_pos(int n)
{	
	/*printf("Current : \n");
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) 
			printf("%d", map[i][j]);
		printf("\n");
	}*/
	switch(n) {
		case 1:
			go_right();
			break;
		case 2:
			go_top();
			break;
		case 3:
			go_left();
			break;
		case 4:
			go_bottom();
			break;
	}
	/*printf("After Move %d \n", n);
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) 
			printf("%d", map[i][j]);
		printf("\n");
	}*/

}
void restore_map(int red_row, int red_col, int blue_row, int blue_col, int type)
{
	printf("before : [%d %d %d %d]%d\n", red_row, red_col, red.row, red.col, type);
	print_map();
	if(type == 1) { // 다시 왼쪽으로
		for(int i=red_col;i<=red.col;i++) 
			map[red_row][i] = 1;
		for(int i=blue_col;i<=blue.col;i++)
			map[blue_row][i] = 1;
	}
	if(type == 2) { // 다시 밑으로
		for(int i=red_row;i>=red.row;i--) 
			map[i][red_col] = 1;
		for(int i=blue_row;i>=blue.row;i--)
			map[i][blue_col] = 1;
	}
	if(type == 3) { //다시 오른쪽으로
		for(int i=red_col;i>=red.col;i--) 
			map[red_row][i] = 1;
		for(int i=blue_col;i>=blue.col;i--)
			map[blue_row][i] = 1;
	}
	if(type == 4) { // 다시 위로
		for(int i=red_row;i<=red.row;i++) 
			map[i][red_col] = 1;
		for(int i=blue_row;i<=blue.row;i++)
			map[i][blue_col] = 1;
	}
	map[red_row][red_col] = 2;
	map[blue_row][blue_col] = 3;
	map[end.row][end.col] = 4;
	red.row = red_row;
	red.col = red_col;
	blue.row = blue_row;
	blue.col = blue_col;
	printf("after : \n");
	print_map();
}
int direction[MAX];
int result = 100;
void dfs(int depth, int time_out, int color, int from) 
{
	int red_row = red.row, red_col = red.col;
	int blue_row = blue.row, blue_col = blue.col;
	//printf("Current Depth : %d [%d] [%d %d][%d %d]\n", 
	//		depth, from, red.row, red.col, blue.row, blue.col);

	if(depth > time_out) {
		//printf("Time out\n");
		return;
	}
	if(map[end.row][end.col] == 5 || map[end.row][end.col] == 6) {		
		printf("Red Goal %d[%d %d][%d %d]\n", 
					depth, red.row, red.col, blue.row, blue.col);
		for(int i=0;i<depth;i++)
			printf("%d ", direction[i]);
		printf("\n");
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) 
				printf("%d", map[i][j]);
			printf("\n");
		}
		if(red.row == blue.row && red.col == blue.col)
			return;
		if(blue.row == end.row && blue.col == end.col)
			return;

		if(depth < result)
			result = depth;
		return;
	}
	// Red go right
	if(map[red.row][red.col+1] == 1 || map[red.row][red.col+1] == 4) {
		if(from != 3) { 
			direction[depth] = 1;
			move_pos(1);
			dfs(depth+1, time_out, 0, 1);
			restore_map(red_row, red_col, blue_row, blue_col, 1);
			direction[depth] = 0;
		}
	}
	// Red go top
	if(map[red.row-1][red.col] == 1 || map[red.row-1][red.col] == 4) {
		if(from != 4) { 
			direction[depth] = 2;
			move_pos(2);
			dfs(depth+1, time_out, 0, 2);
			restore_map(red_row, red_col, blue_row, blue_col, 2);
			direction[depth] = 0;
		}
	} 
	// Red go left
	if(map[red.row][red.col-1] == 1 || map[red.row][red.col-1] == 4) {
		if(from != 1) { 
			direction[depth] = 3;
			move_pos(3);
			dfs(depth+1, time_out, 0, 3);
			restore_map(red_row, red_col, blue_row, blue_col, 3);
			direction[depth] = 0;
		}
	}
	// Red go bottom
	if(map[red.row+1][red.col] == 1 || map[red.row+1][red.col] == 4) { 
		if(from != 2) { 
			direction[depth] = 4;
			move_pos(4);
			dfs(depth+1, time_out, 0, 4);
			restore_map(red_row, red_col, blue_row, blue_col, 4);
			direction[depth] = 0;
		}
	}
	// Blue go right
	if(map[blue.row][blue.col+1] == 1 || map[blue.row][blue.col+1] == 4) {
		if(from != 3) { 
			direction[depth] = 1;
			move_pos(1);
			dfs(depth+1, time_out, 1, 1);
			restore_map(red_row, red_col, blue_row, blue_col, 1);
			direction[depth] = 0;
		}
	}
	// Blue go top
	if(map[blue.row-1][blue.col] == 1 || map[blue.row-1][blue.col] == 4) {
		if(from != 4) { 
			direction[depth] = 2;
			move_pos(2);
			dfs(depth+1, time_out, 1, 2);
			restore_map(red_row, red_col, blue_row, blue_col, 2);
			direction[depth] = 0;
		}
	} 
	// Blue go left
	if(map[blue.row][blue.col-1] == 1 || map[blue.row][blue.col-1] == 4) { 
		if(from != 1) { 
			direction[depth] = 3;
			move_pos(3);
			dfs(depth+1, time_out, 1, 3);
			restore_map(red_row, red_col, blue_row, blue_col, 3);
			direction[depth] = 0;
		}
	}
	// Blue go bottom
	if(map[blue.row+1][blue.col] == 1 || map[blue.row+1][blue.col] == 4) { 
		if(from != 2) { 
			direction[depth] = 4;
			move_pos(4);
			dfs(depth+1, time_out, 1, 4);
			restore_map(red_row, red_col, blue_row, blue_col, 4);
			direction[depth] = 0;
		}
	}
}
int main()
{
	char a;
	scanf("%d %d\n", &N, &M);
	//printf("%d %d\n", N, M);
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			a = getchar();
			//printf("%c", a);
			switch(a) {
				case '#':
					map[i][j] = 0;
					break;
				case '.':
					map[i][j] = 1;
					break;
				case 'R':
					map[i][j] = 2;
					red.row = i;
					red.col = j;
					break;
				case 'B':
					map[i][j] = 3;
					blue.row = i;
					blue.col = j;
					break;
				case 'O':
					map[i][j] = 4;
					end.row = i;
					end.col = j;
					break;	
			}
		}
		a = getchar();
		//printf("%c", a);
	}
	
	/*go_bottom();
	print_map();
	go_right();
	print_map();
	go_top();
	print_map();*/


	dfs(0, 10, -1, -1);
	if(result == 100)
		result = -1;
	printf("%d\n", result);
	return 0;
}
