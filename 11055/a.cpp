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

int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	vector<int> seq(N, 0);
	vector<int> dp(N, 0);
	for(int i=0;i<N;i++) {
		cin >> seq[i];
		dp[i] = seq[i];
	}
	
	int max = -1;
	for(int i=0;i<N;i++) {
		for(int j=0;j<i;j++) 
			if(seq[j] < seq[i] && (dp[j] + seq[i] > dp[i])) 
				dp[i] = dp[j] + seq[i];
		max = dp[i] > max ? dp[i] : max;
	}	

	cout << max << "\n";	
	return 0;
}
