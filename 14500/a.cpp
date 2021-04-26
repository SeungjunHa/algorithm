#include <cstdio>
#include <queue>
#include <vector>

int map[500][500];

int N, M;
void print_map()
{
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) 
			printf("|%d|", map[i][j]);
		printf("\n");
	}
}
#define PRINT 1
int max = 0;
int target_row[4];
int target_col[4];
int is_safe_range(int row[4], int col[4])
{
	int possible = 1;
	for(int i=0;i<4;i++) {
		if( (row[i] < 0 || row[i] >= N) || (col[i] < 0 || col[i] >= M) ) {
			possible = 0;
			break;
		}
	}
	return possible;
}
void body(int row[4], int col[4])
{
	int temp = 0;
	if(is_safe_range(row, col)) {
		for(int i=0;i<4;i++) 
			temp += map[row[i]][col[i]];
		
		if(temp > max)
			max = temp;
	}
}

void type1(int row, int col)
{ 
	target_row[0] = row; target_col[0] = col;
	target_row[1] = row; target_col[1] = col+1;
	target_row[2] = row; target_col[2] = col+2;
	target_row[3] = row; target_col[3] = col+3;
	body(target_row, target_col);
}
void type2(int row, int col)
{
	target_row[0] = row;   target_col[0] = col;
	target_row[1] = row+1; target_col[1] = col;
	target_row[2] = row+2; target_col[2] = col;
	target_row[3] = row+3; target_col[3] = col;
	body(target_row, target_col);
}

void type3(int row, int col)
{
	target_row[0] = row;   target_col[0] = col;
	target_row[1] = row;   target_col[1] = col+1;
	target_row[2] = row+1; target_col[2] = col;
	target_row[3] = row+1; target_col[3] = col+1;
	body(target_row, target_col);
}

void type4(int row, int col)
{
	target_row[0] = row;   target_col[0] = col;
	target_row[1] = row+1; target_col[1] = col;
	target_row[2] = row+2; target_col[2] = col;
	target_row[3] = row+2; target_col[3] = col+1;
	body(target_row, target_col);
}
void type5(int row, int col)
{
	target_row[0] = row;   target_col[0] = col;
	target_row[1] = row;   target_col[1] = col+1;
	target_row[2] = row;   target_col[2] = col+2;
	target_row[3] = row-1; target_col[3] = col+2;
	body(target_row, target_col);
}
void type6(int row, int col)
{
	target_row[0] = row;   target_col[0] = col;
	target_row[1] = row-1; target_col[1] = col;
	target_row[2] = row-2; target_col[2] = col;
	target_row[3] = row-2; target_col[3] = col-1;
	body(target_row, target_col);
}
void type7(int row, int col)
{
	target_row[0] = row;   target_col[0] = col;
	target_row[1] = row;   target_col[1] = col-1;
	target_row[2] = row;   target_col[2] = col-2;
	target_row[3] = row+1; target_col[3] = col-2;
	body(target_row, target_col);
}

void type8(int row, int col)
{
	target_row[0] = row;   target_col[0] = col;
	target_row[1] = row+1; target_col[1] = col;
	target_row[2] = row+2; target_col[2] = col;
	target_row[3] = row+2; target_col[3] = col-1;
	body(target_row, target_col);
}
void type9(int row, int col)
{
	target_row[0] = row;   target_col[0] = col;
	target_row[1] = row;   target_col[1] = col+1;
	target_row[2] = row;   target_col[2] = col+2;
	target_row[3] = row+1; target_col[3] = col+2;
	body(target_row, target_col);
}
void type10(int row, int col)
{
	target_row[0] = row;   target_col[0] = col;
	target_row[1] = row-1; target_col[1] = col;
	target_row[2] = row-2; target_col[2] = col;
	target_row[3] = row-2; target_col[3] = col+1;
	body(target_row, target_col);
}
void type11(int row, int col)
{
	target_row[0] = row;   target_col[0] = col;
	target_row[1] = row;   target_col[1] = col-1;
	target_row[2] = row;   target_col[2] = col-2;
	target_row[3] = row-1; target_col[3] = col-2;
	body(target_row, target_col);
}

void type12(int row, int col)
{
	target_row[0] = row;   target_col[0] = col;
	target_row[1] = row+1; target_col[1] = col;
	target_row[2] = row+1; target_col[2] = col+1;
	target_row[3] = row+2; target_col[3] = col+1;
	body(target_row, target_col);
}
void type13(int row, int col)
{
	target_row[0] = row;   target_col[0] = col;
	target_row[1] = row;   target_col[1] = col+1;
	target_row[2] = row-1; target_col[2] = col+1;
	target_row[3] = row-1; target_col[3] = col+2;
	body(target_row, target_col);
}
void type14(int row, int col)
{
	target_row[0] = row;   target_col[0] = col;
	target_row[1] = row-1; target_col[1] = col;
	target_row[2] = row-1; target_col[2] = col-1;
	target_row[3] = row-2; target_col[3] = col-1;
	body(target_row, target_col);
}
void type15(int row, int col)
{
	target_row[0] = row;   target_col[0] = col;
	target_row[1] = row;   target_col[1] = col-1;
	target_row[2] = row+1; target_col[2] = col-1;
	target_row[3] = row+1; target_col[3] = col-2;
	body(target_row, target_col);
}

void type16(int row, int col)
{
	target_row[0] = row;   target_col[0] = col;
	target_row[1] = row+1; target_col[1] = col;
	target_row[2] = row+1; target_col[2] = col-1;
	target_row[3] = row+2; target_col[3] = col-1;
	body(target_row, target_col);
}
void type17(int row, int col)
{
	target_row[0] = row;   target_col[0] = col;
	target_row[1] = row;   target_col[1] = col+1;
	target_row[2] = row+1; target_col[2] = col+1;
	target_row[3] = row+1; target_col[3] = col+2;
	body(target_row, target_col);
}
void type18(int row, int col)
{
	target_row[0] = row;   target_col[0] = col;
	target_row[1] = row-1; target_col[1] = col;
	target_row[2] = row-1; target_col[2] = col+1;
	target_row[3] = row-2; target_col[3] = col+1;
	body(target_row, target_col);
}
void type19(int row, int col)
{
	target_row[0] = row;   target_col[0] = col;
	target_row[1] = row;   target_col[1] = col-1;
	target_row[2] = row-1; target_col[2] = col-1;
	target_row[3] = row-1; target_col[3] = col-2;
	body(target_row, target_col);
}

void type20(int row, int col)
{
	target_row[0] = row;   target_col[0] = col;
	target_row[1] = row;   target_col[1] = col+1;
	target_row[2] = row;   target_col[2] = col+2;
	target_row[3] = row+1; target_col[3] = col+1;
	body(target_row, target_col);
}
void type21(int row, int col)
{
	target_row[0] = row;   target_col[0] = col;
	target_row[1] = row-1; target_col[1] = col;
	target_row[2] = row-2; target_col[2] = col;
	target_row[3] = row-1; target_col[3] = col+1;
	body(target_row, target_col);
}
void type22(int row, int col)
{
	target_row[0] = row;   target_col[0] = col;
	target_row[1] = row;   target_col[1] = col-1;
	target_row[2] = row;   target_col[2] = col-2;
	target_row[3] = row-1; target_col[3] = col-1;
	body(target_row, target_col);
}
void type23(int row, int col)
{
	target_row[0] = row;   target_col[0] = col;
	target_row[1] = row+1; target_col[1] = col;
	target_row[2] = row+2; target_col[2] = col;
	target_row[3] = row+1; target_col[3] = col-1;
	body(target_row, target_col);
}

void simulation(int row, int col)
{
	type1(row, col);
	type2(row, col);
	type3(row, col);
	type4(row, col);
	type5(row, col);
	type6(row, col);
	type7(row, col);
	type8(row, col);
	type9(row, col);
	type10(row, col);
	type11(row, col);
	type12(row, col);
	type13(row, col);
	type14(row, col);
	type15(row, col);
	type16(row, col);
	type17(row, col);
	type18(row, col);
	type19(row, col);
	type20(row, col);
	type21(row, col);
	type22(row, col);
	type23(row, col);
}
int main()
{
	scanf("%d %d\n", &N, &M);
	for(int i=0;i<N;i++) 
		for(int j=0;j<M;j++) 
			scanf("%d", &map[i][j]);
		
	//print_map();	

	for(int i=0;i<N;i++) 
		for(int j=0;j<M;j++) 
			simulation(i, j);
		
	printf("%d\n", max);
}
