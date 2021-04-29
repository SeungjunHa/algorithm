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

int result = 0;
#if 0
// BFS
queue<pair<int, int>> q;
void bfs(int N)
{
	q.push( {N, 0 } );
	while(!q.empty()) {
		pair<int, int> p = q.front(); q.pop();
		if(p.first != 1) {
			if(p.first % 3 == 0)
				q.push( { p.first/3, p.second+1} );
			if(p.first % 2 == 0)
				q.push( { p.first/2, p.second+1} );
			q.push( { p.first - 1, p.second+1} );
		} else {
			result = p.second;
			break;
		}
	}
}
#endif
static inline
int dp(int N)
{
	if(N < 2)
		return 0;
	int a0 = dp(N / 2) + N % 2 + 1;
	int a1 = dp(N / 3) + N % 3 + 1;
	return a0 > a1 ? a1 : a0;
}
int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	//bfs(N);
	result = dp(N);
	cout << result << "\n";
	return 0;
}
