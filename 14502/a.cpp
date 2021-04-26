#include <cstdio>
#include <vector>

int N, M;
int NM;
int map[8][8];

int result = 0;

int arr[100];

void print_map(int cmap[8][8])
{
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) 
			printf("|%d|", cmap[i][j]);
		printf("\n");
	}
}
int init_virus[100];
int init_v = 0;
void spread_virus(int cmap[8][8], int arr[3])
{	
	int front = 0, rear = 0;
	int queue[100];
	for(int i=0;i<100;i++)
		queue[i] = 0;

	for(int i=0;i<init_v;i++) {
		queue[rear % 100] = init_virus[i];
		rear++;
	}

	while(front != rear) {
		int current = queue[front % 100], crow;
		int target, row, col;
		front++;
		crow = (int)(current / M);

		target = current - M;
		row = (int)(target / M);
		col = (target % M);
		if(target >= 0 && row < crow) {
			if(cmap[row][col] == 0) {
				queue[rear % 100] = target;
				rear++;
				cmap[row][col] = 2;
			}
		}
		target = current + M;
		row = (int)(target / M);
		col = (target % M);
		if(target < NM && row > crow) {
			if(cmap[row][col] == 0) {
				queue[rear % 100] = target;
				rear++;
				cmap[row][col] = 2;
			}
		}
		target = current + 1;
		row = (int)(target / M);
		col = (target % M);
		if(target < NM && row == crow) {
			if(cmap[row][col] == 0) {
				queue[rear % 100] = target;
				rear++;
				cmap[row][col] = 2;
			}
		}
		target = current - 1;
		row = (int)(target / M);
		col = (target % M);
		if(target >= 0 && row == crow) {
			if(cmap[row][col] == 0) {
				queue[rear % 100] = target;
				rear++;
				cmap[row][col] = 2;
			}
		}
	}
}
void count_map(int cmap[8][8], int arr[3]) 
{
	int walls = 0;
	int virus = 0;

	spread_virus(cmap, arr);
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			virus += cmap[i][j] == 2 ? 1 : 0;
			walls += cmap[i][j] == 1 ? 1 : 0;
		}
	}
	int candi = NM - virus - walls;
	if(candi > result)
		result = candi;
}
void dfs(int depth, int r)
{
	if(depth == 3) {
		int possible = 1;
		int copy_map[8][8];
		for(int i=0;i<8;i++) 
			for(int j=0;j<8;j++) 
				copy_map[i][j] = map[i][j];
				
		for(int i=0;i<depth;i++) {
			int row = (int)(arr[i]/M);
			int col = (arr[i] % M);
			if(copy_map[row][col] == 1 || copy_map[row][col] == 2) {
				possible = 0;
				break;
			}	
			copy_map[row][col] = 1;	
		}
		if(possible) 
			count_map(copy_map, arr);	
		return;
	}

	for(int i=r;i<NM;i++) {
		arr[depth] = i;
		dfs(depth+1, i+1);
	}
}
int main()
{
	scanf("%d %d\n", &N, &M);
	for(int i=0;i<N;i++) 
		for(int j=0;j<M;j++) 
			scanf("%d ", &map[i][j]);

	NM = N*M;

	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++) 
			if(map[i][j] == 2) {
				init_virus[init_v] = i*M + j;
				init_v++;
			}
	dfs(0, 0);		

	printf("%d\n", result);
	return 0;
}
