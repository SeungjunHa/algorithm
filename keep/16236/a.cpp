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
// 자기보다 큰 크기가 있으면 그 칸 못지나감
// 자기보다 작은 크기만 먹기 가능
// 크기가 같으면 지나가기는 되는데, 먹기는 불가

int N;

typedef struct __pos {
	int row;
	int col;
}Pos;

typedef struct __baby {
	Pos pos;
	int size;
	int eat;
}Baby;

Baby baby;
vector<int> shark[6];
int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<vector<int>> map(N, vector<int>(N, 0));
	for(int i=0;i<N;i++) 
		for(int j=0;j<N;j++) {
			cin >> map[i][j];
			if(map[i][j] == 9) {
				baby.pos.row = i;
				baby.pos.col = j;
			} else {
				shark[map[i][j]].row = i;
				shark[map[i][j]].col = j;
			}
		}	
	baby.size = 2;
	baby.eat = 0;
	

	return 0;
}
