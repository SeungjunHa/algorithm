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
	int cnt = 0;
	while(1) {
		if(N % 5 == 0) {
			cnt += N / 5;
			break;
		}
		N -= 3;
		cnt++;
		if(N < 0) {
			cnt = -1;
			break;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
