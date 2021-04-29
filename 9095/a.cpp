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
int dp(int num)
{	
	if(num == 0 || num == 1)
		return 1;
	if(num == 2)
		return 2;
	if(num >= 3)
		return dp(num - 1) + dp(num - 2) + dp(num - 3);
}
int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	
	for(int iter=0;iter<N;iter++) {
		int num;
		cin >> num;
		result = dp(num);
		cout << result << "\n";
		result = 0;
	}
	
	return 0;
}
