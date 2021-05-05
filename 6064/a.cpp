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

int gcd(int a, int b)
{
	int r;
	while(b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for(int iter=0;iter<T;iter++) {
		int answer, M, N, x, y, i;
		cin >> M >> N >> x >> y;
		int g = ((M*N)/gcd(M, N));
		for(i=x; i<=g; i+=M) {
			answer = (i % N == 0) ? N : (i % N);
			if(answer == y) 
				break;	
		}
		answer = i > g ? -1 : i;
		cout << answer << "\n";
	}
	return 0;
}
