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
	unsigned long long A,B,C,result=1;
	cin >> A >> B >> C;

	vector<int> bit;
	unsigned long long temp = B, tmp = 0;
	while(1) {
		temp & 1 ? bit.push_back(1 << tmp) : bit.push_back(0);
		temp >>= 1;
		tmp++;
		if(!temp)
			break;
	}
	vector<unsigned long long> remain;
	unsigned long long next;
	remain.push_back(A % C);
	for(int i=1;i<bit.size();i++) {
		next = (remain[i-1] * remain[i-1]) % C;
		remain.push_back(next);
	}
	for(int i=0;i<bit.size();i++) {
		if(!bit[i]) 
			continue;
		result *= remain[i];
		result %= C;
	}
	cout << result << "\n";
	return 0;
}
