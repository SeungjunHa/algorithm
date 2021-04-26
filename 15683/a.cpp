#include <cstdio>
#include <vector>
#include <queue>

int N, M, NM;
int map[8][8];

void print_map(int smap[8][8])
{
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) 
			printf("%d ", smap[i][j]);
		printf("\n");
	}
}

typedef struct pos {
	int row;
	int col;
}POS;

typedef struct cctv {
	POS pos;
	int type;
}CCTV;

CCTV cctv[10];
int num_of_cctv = 0;

int direction[10];

// 동 북 서 남
int drow[4] = { 0, 1, 0, -1 };
int dcol[4] = { 1, 0, -1, 0 };

void fill_copy_map(int row, int col, int type, int direction, int cmap[8][8])
{
	int nrow = row;
	int ncol = col;
	if(type == 1) {
		while(1) {
			nrow += drow[direction];
			ncol += dcol[direction];
			if(nrow < 0 || nrow >= N || ncol < 0|| ncol >= M)
				break;
			if(1 <= cmap[nrow][ncol] && cmap[nrow][ncol] <= 5)
				continue;
			if(cmap[nrow][ncol] == 7)
				continue;
			if(cmap[nrow][ncol] == 6)
				break;
			cmap[nrow][ncol] = 7;	
		}
	}
	if(type == 2) {
		for(int i=0;i<2;i++) {
			while(1) {
				nrow += drow[(direction+i*2) % 4];
				ncol += dcol[(direction+i*2) % 4];
				if(nrow < 0 || nrow >= N || ncol < 0|| ncol >= M)
					break;
				if(1 <= cmap[nrow][ncol] && cmap[nrow][ncol] <= 5)
					continue;
				if(cmap[nrow][ncol] == 7)
					continue;
				if(cmap[nrow][ncol] == 6)
					break;
				cmap[nrow][ncol] = 7;	
			}
			nrow = row;
			ncol = col;
		}
	}
	if(type == 3) {
		for(int i=0;i<2;i++) {
			while(1) {
				nrow += drow[(direction+i) % 4];
				ncol += dcol[(direction+i) % 4];
				if(nrow < 0 || nrow >= N || ncol < 0|| ncol >= M)
					break;
				if(1 <= cmap[nrow][ncol] && cmap[nrow][ncol] <= 5)
					continue;
				if(cmap[nrow][ncol] == 7)
					continue;
				if(cmap[nrow][ncol] == 6)
					break;
				cmap[nrow][ncol] = 7;	
			}
			nrow = row;
			ncol = col;
		}
	}
	if(type == 4) {
		for(int i=0;i<3;i++) {
			while(1) {
				nrow += drow[(direction+i) % 4];
				ncol += dcol[(direction+i) % 4];
				if(nrow < 0 || nrow >= N || ncol < 0|| ncol >= M) 
					break;	
				if(1 <= cmap[nrow][ncol] && cmap[nrow][ncol] <= 5)
					continue;
				if(cmap[nrow][ncol] == 7)
					continue;
				if(cmap[nrow][ncol] == 6)
					break;
				cmap[nrow][ncol] = 7;
			}
			nrow = row;
			ncol = col;
		}
	}
	if(type == 5) {
		for(int i=0;i<4;i++) {		
			while(1) {
				nrow += drow[(direction+i) % 4];
				ncol += dcol[(direction+i) % 4];
				if(nrow < 0 || nrow >= N || ncol < 0|| ncol >= M)
					break;
				if(1 <= cmap[nrow][ncol] && cmap[nrow][ncol] <= 5)
					continue;
				if(cmap[nrow][ncol] == 7)
					continue;
				if(cmap[nrow][ncol] == 6)
					break;
				cmap[nrow][ncol] = 7;	
			}
			nrow = row;
			ncol = col;
		}
	}
}
int min = 100;
void dfs(int depth, int r)
{
	if(depth == num_of_cctv) {
		int cctv_row, cctv_col, cctv_type, cctv_direction;
		int copy_map[8][8];
		for(int i=0;i<N;i++) 
			for(int j=0;j<M;j++)
				copy_map[i][j] = map[i][j];
		for(int i=0;i<depth;i++) {
			cctv_row = cctv[i].pos.row;
			cctv_col = cctv[i].pos.col;
			cctv_type = cctv[i].type;
			cctv_direction = direction[i];
			fill_copy_map(cctv_row, cctv_col, cctv_type, cctv_direction, copy_map);
		}
		int candidate = 0;
		for(int i=0;i<N;i++) 
			for(int j=0;j<M;j++) 
				if(copy_map[i][j] == 0)
					candidate++;
		if(candidate < min)
			min = candidate;	
		return;
	}

	for(int i=0;i<4;i++) {
		direction[depth] = i;
		dfs(depth+1, i+1);
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	NM = N*M;
	for(int i=0;i<N;i++) 
		for(int j=0;j<M;j++) {
			scanf("%d", &map[i][j]);
			if(0 < map[i][j] && map[i][j] < 6) {
				cctv[num_of_cctv].pos.row = i;	
				cctv[num_of_cctv].pos.col = j;	
				cctv[num_of_cctv++].type = map[i][j];
			}			
		}
	
	dfs(0, num_of_cctv);

	printf("%d\n", min);
	return 0;
}






