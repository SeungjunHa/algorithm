#include <cstdio>
#include <vector>

int N, M;
int map[50][50];

#define abs_minus(a, b) ((a > b) ? (a - b) : (b - a))

typedef struct __pos {
	int row;
	int col;
}POS;

POS home_pos[50];
POS chicken_pos[13];
int home_num = 0;
int chicken_num = 0;

void print_map(int smap[50][50])
{
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++)
			printf("%d", map[i][j]);
		printf("\n");
	}
}

int min = 99999999;
void get_chicken_distance(POS target[13], int target_num)
{
	int distance[home_num];
	int candidate = 0;
	int dist = 0;
	for(int i=0;i<home_num;i++) {
		distance[i] = 10000;
		for(int j=0;j<target_num;j++) {
			dist = (abs_minus(home_pos[i].row, target[j].row) + 
								abs_minus(home_pos[i].col, target[j].col));
			if(dist < distance[i])
				distance[i] = dist;
		}
		candidate += distance[i];
	}
	if(candidate < min)
		min = candidate;
}
POS alive[13];
void dfs(int depth, int r)
{
	if(depth == M) {
		get_chicken_distance(alive, depth);
		return;
	}	

	for(int i=r;i<chicken_num;i++) {
		alive[depth] = chicken_pos[i];
		dfs(depth+1, i+1);
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			scanf("%d", &map[i][j]);
			if(map[i][j] == 1) {
				home_pos[home_num].row = i;
				home_pos[home_num++].col = j;
			} else if(map[i][j] == 2) {
				chicken_pos[chicken_num].row = i;
				chicken_pos[chicken_num++].col = j;
			}
		}
	}
	
	dfs(0, 0);
	printf("%d\n", min);
}
