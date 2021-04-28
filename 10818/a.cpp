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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	int min = INT_MIN;
	int max = INT_MAX;
	int num;
	for(int i=0;i<N;i++) {
		cin >> num;
		max = num > max ? num : max;
		min = num < min ? num : min;
	}
	cout << min << " " << max << "\n";	
	return 0;
}
