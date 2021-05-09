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

int N;
int map[21][21];
int smap[21][21];
int already[21][21];
int op[5];
unsigned long long max_c = 0;

void move_right()
{
	for(int i=0;i<N;i++) 
		for(int j=0;j<N;j++) 
			already[i][j] = 0;

	for(int i=0;i<N;i++) {
		for(int j=N-2;j>=0;j--) {
			for(int k=j; k<N-1; k++) {
				if(smap[i][k+1] == 0) {
					smap[i][k+1] = smap[i][k];
					smap[i][k] = 0;
				} else if(smap[i][k+1] == smap[i][k] && already[i][k+1] == 0) {
					already[i][k+1] = 1;
					smap[i][k+1] *= 2;
					smap[i][k] = 0;
					break;
				} else
					break;
			}
		}	
	}
}
void move_up()
{
	for(int i=0;i<N;i++) 
		for(int j=0;j<N;j++) 
			already[i][j] = 0;

	for(int i=0;i<N;i++) {
		for(int j=1;j<N;j++) {
			for(int k=j; k>0; k--) {
				if(smap[k-1][i] == 0) {
					smap[k-1][i] = smap[k][i];
					smap[k][i] = 0;
				} else if(smap[k-1][i] == smap[k][i] && already[k-1][i] == 0) {
					already[k-1][i] = 1;
					smap[k-1][i] *= 2;
					smap[k][i] = 0;
					break;
				} else 
					break;
			}
		}	
	}
}
void move_left()
{
	for(int i=0;i<N;i++) 
		for(int j=0;j<N;j++) 
			already[i][j] = 0;

	for(int i=0;i<N;i++) {
		for(int j=1;j<N;j++) {
			for(int k=j; k>0; k--) {
				if(smap[i][k-1] == 0) {
					smap[i][k-1] = smap[i][k];
					smap[i][k] = 0;
				} else if(smap[i][k-1] == smap[i][k] && already[i][k-1] == 0) {
					already[i][k-1] = 1;
					smap[i][k-1] *= 2;
					smap[i][k] = 0;
					break;
				} else 
					break;
			}
		}	
	}
}
void move_down()
{
	for(int i=0;i<N;i++) 
		for(int j=0;j<N;j++) 
			already[i][j] = 0;
		
	for(int i=0;i<N;i++) {
		for(int j=N-2;j>=0;j--) {
			for(int k=j; k<N-1; k++) {
				if(smap[k+1][i] == 0) {
					smap[k+1][i] = smap[k][i];
					smap[k][i] = 0;
				} else if(smap[k+1][i] == smap[k][i] && already[k+1][i] == 0) {
					already[k+1][i] = 1;
					smap[k+1][i] *= 2;
					smap[k][i] = 0;
					break;
				} else
					break;
			}
		}	
	}
}
void dfs(int depth, int r, int max)
{
	if(depth == max) {
		for(int i=0;i<max;i++) {
			if(op[i] == 0) 
				move_right();
			else if(op[i] == 1) 
				move_up();
			else if(op[i] == 2) 
				move_left();
			else if(op[i] == 3) 
				move_down();
		}
		for(int i=0;i<N;i++) 
			for(int j=0;j<N;j++) 
				max_c = max_c > smap[i][j] ? max_c : smap[i][j];
			
		for(int i=0;i<N;i++) 
			for(int j=0;j<N;j++) 
				smap[i][j] = map[i][j];

		return;
	}
	for(int i=0;i<4;i++) {
		op[depth] = i;
		dfs(depth+1, i, max);
	}
}

// 0 : 우측으로, 1 : 위로, 2 : 왼쪽으로, 3 : 밑으로

int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	for(int i=0;i<N;i++) 
		for(int j=0;j<N;j++) {
			cin >> map[i][j];
			smap[i][j] = map[i][j];
		}
	dfs(0, 0, 5);

	printf("%lld\n", max_c);
	return 0;
}
