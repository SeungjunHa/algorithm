#include <stdio.h>

int N;
int map[22][22];

void print_map(const char *s, int smap[22][22])
{
#if 1
	printf("%s\n", s);
	for(int i=0;i<N+2;i++) {
		for(int j=0;j<N+2;j++) 
			printf("%d ", smap[i][j]);
		printf("\n");
	}
#endif
}
void move_upper(int smap[22][22])
{	
	int i,j;
	print_map("Before move upper", smap);
	int already[22][22];
	for(int i=0;i<22;i++)
		for(int j=0;j<22;j++)
			already[i][j] = 0;
	for(i=1;i<N+1;i++) {
		for(j=1;j<N+1;j++) {
			if(smap[j][i] == 0) 
				continue;
			int move = 0;
			while(1) {
				if(smap[j-1-move][i] == 1)
					break;
				if(smap[j-1-move][i] != 0) {
					if(smap[j-1-move][i] == smap[j-move][i] &&
						already[j-1-move][i] == 0) {
						smap[j-1-move][i] <<= 1;
						smap[j-move][i] = 0;	
						already[j-1-move][i] = 1;
					}
					break;
				}
				smap[j-1-move][i] = smap[j-move][i];
				smap[j-move][i] = 0;
				move++;
			}
		}
	}
	print_map("After move upper", smap);
}
void move_lower(int smap[22][22]) 
{
	int i,j;
	print_map("Before move lower", smap);
	int already[22][22];
	for(int i=0;i<22;i++)
		for(int j=0;j<22;j++)
			already[i][j] = 0;
	for(i=1;i<N+1;i++) {
		for(j=N;j>=1;j--) {
			if(smap[j][i] == 0) 
				continue;
			int move = 0;
			while(1) {
				if(smap[j+1+move][i] == 1)
					break;
				if(smap[j+1+move][i] != 0) {
					if(smap[j+1+move][i] == smap[j+move][i] &&
						already[j+1+move][i] == 0) {
						smap[j+1+move][i] <<= 1;
						smap[j+move][i] = 0;	
						already[j+1+move][i] = 1;
					}
					break;
				}
				smap[j+1+move][i] = smap[j+move][i];
				smap[j+move][i] = 0;
				move++;
			}
		}
	}
	print_map("After move lower", smap);
}
void move_left(int smap[22][22])
{
	int i,j;
	print_map("Before move left", smap);
	int already[22][22];
	for(int i=0;i<22;i++)
		for(int j=0;j<22;j++)
			already[i][j] = 0;
	for(i=1;i<N+1;i++) {
		for(j=1;j<N+1;j++) {
			if(smap[i][j] == 0) 
				continue;
			int move = 0;
			while(1) {
				if(smap[i][j-1-move] == 1)
					break;
				if(smap[i][j-1-move] != 0) {
					if(smap[i][j-1-move] == smap[i][j-move] && 
						already[i][j-1-move] == 0) {
						smap[i][j-1-move] <<= 1;
						smap[i][j-move] = 0;
						already[i][j-1-move] = 1;
					}
					break;
				}
				smap[i][j-1-move] = smap[i][j-move];
				smap[i][j-move] = 0;
				move++;
			}
		}
	}
	print_map("After move left", smap);
}
void move_right(int smap[22][22])
{
	int i,j;
	print_map("Before move right", smap);
	int already[22][22];
	for(int i=0;i<22;i++)
		for(int j=0;j<22;j++)
			already[i][j] = 0;
	for(i=1;i<N+1;i++) {
		for(j=N;j>=1;j--) {
			if(smap[i][j] == 0) 
				continue;
			int move = 0;
			while(1) {
				if(smap[i][j+1+move] == 1)
					break;
				if(smap[i][j+1+move] != 0) {
					if(smap[i][j+1+move] == smap[i][j+move] &&
						already[i][j+1+move] == 0) {
						smap[i][j+1+move] <<= 1;
						smap[i][j+move] = 0;	
						already[i][j+1+move] = 1;
					}
					break;
				}
				smap[i][j+1+move] = smap[i][j+move];
				smap[i][j+move] = 0;
				move++;
			}
		}
	}
	print_map("After move right", smap);
}
void move(int n, int stack_map[22][22])
{
	// 상하좌우 : 0123
	switch(n) {
		case 0:
			move_upper(stack_map);
			break;
		case 1:
			move_lower(stack_map);
			break;
		case 2:
			move_left(stack_map);
			break;
		case 3:
			move_right(stack_map);
			break;
	}
}
// 0을 가면 다시 1로 가면 안됨
int max = 0;
int from_arr[4] = { 1, 0, 3, 2 };

#define MAX 100

int queue[MAX];
int front, rear;

void bfs(int depth, int from, int before_map[22][22])
{
	//printf("Current depth : %d\n", depth);
	if(depth > 5) {
		for(int i=1;i<N+1;i++)
			for(int j=1;j<N+1;j++)
				if(before_map[i][j] > max)
					max = before_map[i][j];
		return;
	}

	int stack_map[22][22];
	for(int i=0;i<4;i++) {
		if(i != from) { 
			//printf("Direction : %d\n", i);
			for(int ii=0;ii<22;ii++) 
				for(int j=0;j<22;j++) 
					stack_map[ii][j] = before_map[ii][j];
			move(i, stack_map);
			bfs(depth+1, from_arr[i], stack_map);	
		}
	}
}
int main()
{
	scanf("%d\n", &N);
	//printf("N : %d\n", N);
	for(int i=0;i<N+2;i++) 
		for(int j=0;j<N+2;j++) 
			map[i][j] = 1;
		
	for(int i=1;i<N+1;i++) {
		for(int j=1;j<N+1;j++) 
			scanf("%d", &map[i][j]);
		getchar();
	}
	//move_lower(map);
	//move_right(map);
	move_left(map);
	//bfs(0, -1, map);
	printf("%d\n", max);
}
