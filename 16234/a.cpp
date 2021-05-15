#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

#define likely(x) __builtin_expect((x), 1)
#define unlikely(x) __builtin_expect((x), 0)

//int map[50][50];
//int visit[50][50];
int map[2500];
int visit[2500];

int N,L,R;
typedef struct __pos {
	int row;
	int col;
}POS;

POS dir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

#define abs_diff(a, b) ((a > b) ? (a - b) : (b - a))

static inline bool can_open(int a, int b)
{
	int diff = abs_diff(a, b);
	return (L <= diff) && (diff <= R);
}
bool simulation()
{
	queue<POS> Q;
	queue<POS> Q1;
	int g_visit = 1;
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			//if(visit[i][j])
			//	continue;
			if(visit[i*N+j])
				continue;
			int map_sum = 0;
			//visit[i][j] = g_visit;
			visit[i*N+j] = g_visit;
			Q.push( {i, j} );
			Q1.push( {i, j} );
			//map_sum += map[i][j];
			map_sum += map[i*N+j];
			while(!Q.empty()) {
				POS cur = Q.front(); Q.pop();
				for(int k=0;k<4;k++) {
					POS ncur;
					ncur.row = cur.row + dir[k].row;
					ncur.col = cur.col + dir[k].col;
					if(ncur.row < 0 || ncur.col < 0 || ncur.row >= N || ncur.col >= N)
						continue;
					//if(!can_open(map[cur.row][cur.col], map[ncur.row][ncur.col])) 
					//	continue;
					//if(visit[ncur.row][ncur.col])
					//	continue;
					//visit[ncur.row][ncur.col] = g_visit;
					if(!can_open(map[cur.row*N+cur.col], map[ncur.row*N+ncur.col])) 
						continue;
					if(visit[ncur.row*N+ncur.col])
						continue;
					visit[ncur.row*N+ncur.col] = g_visit;
					Q.push( ncur );
					Q1.push( ncur );
					//map_sum += map[ncur.row][ncur.col];
					map_sum += map[ncur.row*N+ncur.col];
				}
			}
			int len = Q1.size();
			int avg =(int)(map_sum / len);
			while(!Q1.empty()) {
				POS cur = Q1.front(); Q1.pop();
				//map[cur.row][cur.col] = avg;
				map[cur.row*N+cur.col] = avg;
			}
			if(len > 1) 
				g_visit++;
		}
	}
	return g_visit == 1 ? true : false;
}
int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L >> R;
	for(int i=0;i<N;i++) 
		for(int j=0;j<N;j++) {
			//cin >> map[i][j];
			cin >> map[i*N + j];
		}
	int result = 0;
	bool stop;
	while(1) {
		stop = simulation();
		if(stop)
			break;
		result++;
		//for(int i=0;i<N;i++) 
		//	for(int j=0;j<N;j++)
		//		visit[i][j] = 0;
			//memset(visit[i], 0, sizeof(int)*N);
		memset(visit, 0, sizeof(visit));
	}
	printf("%d\n", result);
	return 0;
}
