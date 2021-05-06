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

#define tripple_min(a, b, c, r) \
	do { \
		r = a > b ? b : a; \
		r = r > c ? c : r; \
	} while(0)


int dp[1001][3];

int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<vector<int>> arr;
	int result;
	for(int iter=0;iter<N;iter++) {
		vector<int> tmp(N, 0);
		cin >> tmp[0] >> tmp[1] >> tmp[2];
		arr.push_back(tmp);
	}

	for(int i=0;i<3;i++)
		dp[0][i] = arr[0][i];
	for(int i=1;i<N;i++) {
		dp[i][0] = arr[i][0] + min(dp[i-1][1], dp[i-1][2]);
		dp[i][1] = arr[i][1] + min(dp[i-1][0], dp[i-1][2]);
		dp[i][2] = arr[i][2] + min(dp[i-1][0], dp[i-1][1]);
	}
	
	tripple_min(dp[N-1][0], dp[N-1][1], dp[N-1][2], result);
	cout << result << "\n";
	return 0;
}
