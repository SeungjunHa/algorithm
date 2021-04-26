#include <cstdio>
#include <queue>
#include <vector>

int N;
int num_of_team;
int link_team[10];
int start_team[10];
int team_check[20];
int map[20][20];

#define abs(a, b) \
	a > b ? a-b : b-a
void print_map(int smap[20][20])
{	
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) 
			printf("|%d|", smap[i][j]);
		printf("\n");
	}
}

int result = 100000000;
void dfs(int depth, int r)
{
	if(depth == num_of_team) {
		int num = 0;
		for(int i=0;i<N;i++)
			if(team_check[i] == 0) 
				start_team[num++] = i;
		/*printf("Link Team : ");
		for(int i=0;i<depth;i++) 
			printf("[%d]", link_team[i]);
		printf("\n");
		printf("Start Team : ");
		for(int i=0;i<depth;i++) 
			printf("[%d]", start_team[i]);
		printf("\n");*/
		int row, col, link_sum = 0, start_sum = 0;
		for(int i=0;i<num_of_team;i++) {
			for(int j=i+1;j<num_of_team;j++) {
				row = link_team[i];
				col = link_team[j];
				link_sum += map[row][col];
				link_sum += map[col][row];
				row = start_team[i];
				col = start_team[j];
				start_sum += map[row][col];
				start_sum += map[col][row];
			}
		}
		int diff = abs(link_sum, start_sum);
		result = diff < result ? diff : result;
		return;
	}

	for(int i=r;i<N;i++) {
		team_check[i] = 1;
		link_team[depth] = i;
		dfs(depth+1, i+1);
		team_check[i] = 0;
	}
}
int main()
{
	scanf("%d", &N);
	for(int i=0;i<N;i++) 
		for(int j=0;j<N;j++) 
			scanf("%d", &map[i][j]);
	num_of_team = N/2;

	//print_map(map);

	dfs(0, 0);
	printf("%d\n", result);
}
