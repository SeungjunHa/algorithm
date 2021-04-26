#include <cstdio>
#include <vector>

int map[100][100];
int copy_map[100][100];
int magic[1000];
int N, Q, P2N;
/*
02 03 => 12 02
12 13    13 03

00 01 02 03    30 20 10 00
10 11 12 13 => 31 21 11 01
20 21 22 23    32 22 12 02
30 31 32 33    33 23 13 03

04 05 06 07    34 24 14 04
14 15 16 17 => 35       05
24 25 26 27    36       06
34 35 36 37    37 27 17 07

00 01 02 03 04 05    50 40 30 20 10 00
10 11 12 13 14 15    51             01
20 21 22 23 24 25    52             02
30 31 32 33 34 35 => 53             03
40 41 42 43 44 45    54             04
50 51 52 53 54 55    55 45 35 25 15 05
*/
void print_map(int smap[100][100]) {
	printf("Print map : \n");
	for(int i=0;i<P2N;i++) {
		for(int j=0;j<P2N;j++) 
			printf("%d ", smap[i][j]);
		printf("\n");
	}
}

/*
start_row : 0
start_col : 4
last_row = 3
last_col = 7
num = 4
*/
int amap[100][100];

// 동 서 남 북
int drow[4] = { 0, 0, 1, -1 };
int dcol[4] = { 1, -1, 0, 0 };
void melting_ice()
{
	int cnt, nrow, ncol;
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			cnt = 0;
			for(int k=0;k<4;k++) {
				nrow = i+drow[k];
				ncol = j+dcol[k];
				if(nrow < 0 || nrow >= N || ncol < 0 || ncol >= N)
					continue;
				if(copy_map[nrow][ncol] > 0)
					cnt++;
			}
			if(cnt < 3)
				map[i][j] -= 1;
		}
	}
}

void rotate_map(int start_row, int start_col, int num) 
{
	int temp_arr[100][100];
	int copy[100][100];
	for(int i=start_row; i<start_row+num; i++) 
		for(int j=start_col; j<start_col+num; j++) 
			copy[i-start_row][j-start_col] = map[i][j];
		
	printf("[%d %d %d]\n", start_row, start_col, num);
	for(int i=0; i<num; i++) 
		for(int j=0; j<num; j++) 
			temp_arr[j][num-1-i] = copy[i][j];

	printf("Array : \n");
	for(int i=0;i<num;i++) {
		for(int j=0;j<num;j++)
			printf("%d ", copy[i][j]);
		printf("\n");
	}
	printf("Rotate : \n");
	for(int i=0;i<num;i++) {
		for(int j=0;j<num;j++)
			printf("%d ", temp_arr[i][j]);
		printf("\n");
	}

	for(int i=start_row; i<start_row+num; i++)
		for(int j=start_col; j<start_col+num; j++) 
			map[i][j] = temp_arr[i][j];
		
	print_map(map);
}

void simulation(int n)
{
	// n으로 1, 2, 4, 8 등이 들어옴
	printf("Simulation : %d\n", n);
	int ii, jj;
	if(n == 1) {
		melting_ice();
		return;
	} else {
		int copy[100][100];
		for(int i=0;i<P2N;i+=n) 
			for(int j=0;j<P2N;j+=n) 
				rotate_map(i, j, n);
			
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++) 
				copy_map[i][j] = map[i][j];
		melting_ice();
	}
}
typedef struct pos {
	int row;
	int col;
}POS;
int main()
{
	scanf("%d %d", &N, &Q);
	P2N = 1 << N;
	for(int i=0;i<P2N;i++) {
		for(int j=0;j<P2N;j++) 
			scanf("%d", &map[i][j]);
	}
	for(int i=0;i<Q;i++)
		scanf("%d ", &magic[i]);
	for(int i=0;i<P2N;i++) 
		for(int j=0;j<P2N;j++) 
			amap[i][j] = map[i][j];
	print_map(map);
	for(int i=0;i<Q;i++) {
		magic[i] = 1 << magic[i];
		simulation(magic[i]);
	}
	int max = 0;
	POS queue[1000];
	int front = 0, rear = 0;
	int visit[100][100];
	int nrow, ncol;
	int conti = 0;
	POS new_pos;
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			if(map[i][j] > 0 && visit[i][j] == 0) {
				queue[rear].row = i;
				queue[rear].col = j;
				visit[i][j] = 1;
				rear++;
				max += map[i][j];
				int temp_count = 0;
				while(front != rear) {
					POS cur = queue[front++];
					for(int i=0;i<4;i++) {
						nrow = cur.row + drow[i];
						ncol = cur.col + dcol[i];
						if(map[nrow][ncol] > 0 && visit[nrow][ncol] == 0) {
							visit[nrow][ncol] = 1;
							new_pos.row = nrow;
							new_pos.col = ncol;
							queue[rear++] = new_pos; 
							temp_count++;
							max += map[nrow][ncol];
						}
					}
				}
				if(temp_count > conti)
					conti = temp_count;
			}
			front = 0;
			rear = 0;
		}
	}	
	printf("%d %d\n", max, conti);
	return 0;
}






