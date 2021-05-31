#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

#define likely(x) __builtin_expect((x), 1)
#define unlikely(x) __builtin_expect((x), 0)

int N, M;
vector<vector<char>> origin_map;
vector<vector<char>> map;

typedef struct __ball {
	int row;
	int col;
	int hole;
}Ball;
Ball origin_red, origin_blue;
Ball red, blue, hole;

void right()
{
	int blue_col_start = blue.col;
	int red_col_start = red.col;
	int next;

	while(1) {
		next = blue.col+1;
		if(next >= M)
			break;
		if(map[blue.row][next] != '#' && map[blue.row][next] != 'O')
			blue.col++;
		else if(map[blue.row][next] == 'O') {
			blue.col++;
			blue.hole = 1;
			break;
		} else
			break;
	}	
	while(1) {
		next = red.col+1;
		if(next >= M)
			break;
		if(map[red.row][next] != '#' && map[red.row][next] != 'O')
			red.col++;
		else if(map[red.row][next] == 'O') {
			red.col++;
			red.hole = 1;
			break;
		} else
			break;
	}

	if(red.hole == 1 || blue.hole == 1)
		return;

	if(blue.row == red.row && blue.col == red.col) {
		if(blue_col_start < red_col_start)
			blue.col--;
		else if (blue_col_start > red_col_start)
			red.col--;
	}
}
void move_right()
{
	map[red.row][red.col] = '.';
	map[blue.row][blue.col] = '.';
	right();
	map[red.row][red.col] = 'R';
	map[blue.row][blue.col] = 'B';
}
void left()
{
	int blue_col_start = blue.col;
	int red_col_start = red.col;
	int next;

	while(1) {
		next = blue.col-1;
		if(next < 0)
			break;
		if(map[blue.row][next] != '#' && map[blue.row][next] != 'O')
			blue.col--;
		else if(map[blue.row][next] == 'O') {
			blue.col--;
			blue.hole = 1;
			break;
		} else
			break;
	}	
	while(1) {
		next = red.col-1;
		if(next < 0)
			break;
		if(map[red.row][next] != '#' && map[red.row][next] != 'O')
			red.col--;
		else if(map[red.row][next] == 'O') {
			red.col--;
			red.hole = 1;
			break;
		} else
			break;
	}

	if(red.hole == 1 || blue.hole == 1)
		return;

	if(blue.row == red.row && blue.col == red.col) {
		if(blue_col_start > red_col_start)
			blue.col++;
		else if(blue_col_start < red_col_start)
			red.col++;
	}
}
void move_left()
{
	map[red.row][red.col] = '.';
	map[blue.row][blue.col] = '.';
	left();
	map[red.row][red.col] = 'R';
	map[blue.row][blue.col] = 'B';
}

void up()
{
	int blue_row_start = blue.row;
	int red_row_start = red.row;
	int next;

	while(1) {
		next = blue.row-1;
		if(next < 0)
			break;
		if(map[next][blue.col] != '#' && map[next][blue.col] != 'O')
			blue.row--;
		else if(map[next][blue.col] == 'O') {
			blue.row--;
			blue.hole = 1;
			break;
		} else
			break;
	}
	while(1) {
		next = red.row-1;
		if(next < 0)
			break;
		if(map[next][red.col] != '#' && map[next][red.col] != 'O')
			red.row--;
		else if(map[next][red.col] == 'O') {
			red.row--;
			red.hole = 1;
			break;
		} else
			break;
	}	

	if(red.hole == 1 || blue.hole == 1)
		return;

	if(blue.col == red.col && blue.row == red.row) {
		if(blue_row_start > red_row_start)
			blue.row++;
		else if(blue_row_start < red_row_start)
			red.row++;
	}
}
void move_up()
{
	map[red.row][red.col] = '.';
	map[blue.row][blue.col] = '.';
	up();
	map[red.row][red.col] = 'R';
	map[blue.row][blue.col] = 'B';
}

void down()
{
	int blue_row_start = blue.row;
	int red_row_start = red.row;
	int next;

	while(1) {
		next = blue.row+1;
		if(next >= N)
			break;
		if(map[next][blue.col] != '#' && map[next][blue.col] != 'O')
			blue.row++;
		else if(map[next][blue.col] == 'O') {
			blue.row++;
			blue.hole = 1;
			break;
		} else
			break;
	}
	while(1) {
		next = red.row+1;
		if(next < 0)
			break;
		if(map[next][red.col] != '#' && map[next][red.col] != 'O')
			red.row++;
		else if(map[next][red.col] == 'O') {
			red.row++;
			red.hole = 1;
			break;
		} else
			break;
	}	

	if(red.hole == 1 || blue.hole == 1)
		return;

	if(blue.col == red.col && blue.row == red.row) {
		if(blue_row_start < red_row_start)
			blue.row--;
		else if(blue_row_start > red_row_start)
			red.row--;
	}
}
void move_down()
{
	map[red.row][red.col] = '.';
	map[blue.row][blue.col] = '.';
	down();
	map[red.row][red.col] = 'R';
	map[blue.row][blue.col] = 'B';
}

void print_map()
{	
	printf("[%d] Current Red Ball : [%d, %d]\n", red.hole, red.row, red.col);
	printf("[%d] Current Blue Ball : [%d, %d]\n", blue.hole, blue.row, blue.col);
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) 
			cout << map[i][j];
		cout << endl;
	}
}
void make_map()
{
	for(int i=0;i<N;i++) 
		for(int j=0;j<M;j++) 
			map[i][j] = origin_map[i][j];

	red = origin_red;
	blue = origin_blue;
}

int arr[10];
int result = 0, stop = 0;

void dfs(int depth, int N)
{
	if(depth == N) {
		make_map();
		for(int i=0;i<N;i++) {
			switch(arr[i]) {
				case 0:
					move_right();
					break;
				case 1:
					move_up();
					break;
				case 2:
					move_left();
					break;
				case 3:
					move_down();
					break;
			}
			if(red.hole || blue.hole) 
				break;
			
			map[hole.row][hole.col] = 'O';
		}
		if(red.hole == 1 && blue.hole == 1)
			stop = 2;
		else if(red.hole == 1) {
			result = depth;
			stop = 1;
		}
		return;
	}
	for(int i=0;i<4;i++) {
		arr[depth] = i;
		dfs(depth+1, N);
		if(stop == 1)
			break;
	}
}
int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	
	origin_map.assign(N, vector<char>(M, 0));
	map.assign(N, vector<char>(M, 0));

	for(int i=0;i<N;i++) 
		for(int j=0;j<M;j++) {
			cin >> origin_map[i][j];
			switch(origin_map[i][j]) {
				case('R') :
					origin_red.row = i; 
					origin_red.col = j;
					origin_red.hole = 0;
					break;
				case('B') :
					origin_blue.row = i; 
					origin_blue.col = j;
					origin_blue.hole = 0;
					break;
				case('O') :
					hole.row = i; 
					hole.col = j;
					break;
			}
		}
	for(int i=1;i<=10;i++) {
		stop = 0;
		dfs(0, i);
		if(stop == 1) 
			break;
	}
	if(stop == 1)
		cout << result << endl;
	else
		cout << "-1" << endl;

	return 0;
}
