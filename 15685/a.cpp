#include <cstdio>
#include <vector>
#include <queue>

int N;
int dragon[20][4];
int map[150][150];

int stack1[1024];
int stack2[1024];
int stack1_top = 0;
int stack2_top = 0;

void print_map(int smap[150][150])
{
	for(int y=0;y<10;y++) {
		for(int x=0;x<10;x++) 
			printf("%d ", smap[y][x]);
		printf("\n");
	}
}

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };

int main(void)
{
	scanf("%d", &N);
	for(int i=0;i<N;i++) 
		for(int j=0;j<4;j++) 
			scanf("%d", &dragon[i][j]);
	//map[y][x] 순서로 해야함.
	int x, y, d, g;
	int new_dir;
	for(int i=0;i<N;i++) {
		x = dragon[i][0];
		y = dragon[i][1];
		d = dragon[i][2];
		g = dragon[i][3];
		stack1[stack1_top++] = d;
		for(int j=0;j<g;j++) {
			int stack_top_index = stack1_top - 1;
			for(int k=stack_top_index;k>=0;k--) {
				new_dir = (stack1[k] + 1) % 4;
				stack1[stack1_top++] = new_dir;
			}
		}
		map[y][x] = 1;
		for(int i=0;i<stack1_top;i++) {
			y += dy[stack1[i]];
			x += dx[stack1[i]];
			map[y][x] = 1;
		}
		stack1_top = 0;
	}
	int sum = 0;
	//print_map(map);
	for(int y=0;y<150;y++) {
		for(int x=0;x<150;x++) {
			if(map[y][x] == 1 && map[y][x+1] == 1 && 
				map[y+1][x] == 1 && map[y+1][x+1] == 1) {
				sum++;
			}
		}
	}
	printf("%d\n", sum);
	return 0;
}

