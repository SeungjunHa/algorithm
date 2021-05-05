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
int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for(int iter=0;iter<N;iter++) {
		long long answer = -1;
		unsigned long long M,N,x,y;
		cin >> M >> N >> x >> y;
		unsigned long long target;
		if(x > y) {
			target = x - y;
			unsigned long long temp = 0;
			for(int i=0;i<=M;i++) {
				temp += N;
				if((temp % M) == target) {
					answer = temp+y;
					break;
				}
			}
		} else if(x < y){ 
			target = y - x;
			unsigned long long temp = 0;
			for(int i=0;i<=N;i++) {
				temp += M;
				if((temp % N) == target) {
					answer = temp+x;
					break;
				}
			}
		} else 
			answer = x;
		cout << answer << "\n";
	}

	return 0;
}
