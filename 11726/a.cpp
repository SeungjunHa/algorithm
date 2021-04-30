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

int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<unsigned long long> fibo;
	for(int i=0;i<=1001;i++) {
		if(unlikely(i == 0 || i == 1))
			fibo.push_back(i);
		else
			fibo.push_back((fibo[i-1] + fibo[i-2]) % 10007);
	}

	cout << fibo[N+1] << "\n";
	
	return 0;
}
