#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

#define likely(x) __builtin_expect((x), 1)
#define unlikely(x) __builtin_expect((x), 0)

int N;
typedef struct __pos {
	int row;
	int col;
}Pos;
typedef struct __baby {
	Pos pos;
	int size;
	int eat;
	int step;
}Baby;
Baby baby;
typedef struct __q_entry {
	int row;
	int col;	
	int step;
}Q_entry;

queue<Q_entry> q;

struct compare {
    bool operator()(const Q_entry& s1, const Q_entry& s2)
    {
        if(s1.step == s2.step) {
            if(s1.row == s2.row)
                return s1.col > s2.col;
            return s1.row > s2.row;
        }
        return s1.step > s2.step;
    }
};
priority_queue<Q_entry, vector<Q_entry>, compare> pq;

Pos dir[4] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };


int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<vector<int>> map(N, vector<int>(N, 0));
	vector<vector<int>> visit(N, vector<int>(N, 0));
	vector<int> fish(7, 0);
	for(int i=0;i<N;i++) 
		for(int j=0;j<N;j++) {
			cin >> map[i][j];
			if(map[i][j] == 9) {
				baby.pos.row = i;
				baby.pos.col = j;
				q.push({i, j, 0});
				continue;
			} 
			fish[map[i][j]]++;
		}
	int stop_flag = 1;
	if(fish[0] == N*N-1) {
		cout << "0\n";
		return 0;
	}
	baby.size = 2;
	baby.eat = 0;
	baby.step = 0;
	while(1) {
		int current_sum = 0;
		for(int i=1; i<baby.size; i++) 
			current_sum += fish[i];

		while(!q.empty()) {
			Q_entry cur = q.front(); q.pop();
			Q_entry n;
			for(int i=0;i<4;i++) {
				n.row = cur.row + dir[i].row;
				n.col = cur.col + dir[i].col;
				n.step = cur.step + 1;
				if(n.row < 0 || n.row > N-1 || n.col < 0 || n.col > N-1)
					continue;
				if(visit[n.row][n.col] == 1)
					continue;
				visit[n.row][n.col] = 1;
				if(map[n.row][n.col] > baby.size) 
					continue;
				q.push( {n.row, n.col, n.step} );
				if(map[n.row][n.col] < baby.size && map[n.row][n.col] != 0)
					pq.push( {n.row, n.col, n.step} );
			}
			if(pq.size() == current_sum)
				break;
		}
		if(pq.empty())
			break;
		Q_entry cur;
		cur = pq.top(); pq.pop();

		while(!q.empty()) 
			q.pop();
		while(!pq.empty()) 
			pq.pop();

		q.push( {cur.row, cur.col, 0} );
		fish[map[cur.row][cur.col]] -= 1;
		map[baby.pos.row][baby.pos.col] = 0;
		map[cur.row][cur.col] = 0;	
		baby.step += cur.step;
		baby.pos.row = cur.row;
		baby.pos.col = cur.col;
		baby.eat += 1;
		if(baby.eat == baby.size) {
			baby.eat = 0;
			baby.size += 1;
		}
		for(int k=0;k<N;k++)
			for(int p=0;p<N;p++)
				visit[k][p] = 0;
	}
	cout << baby.step << "\n";

	return 0;
}
