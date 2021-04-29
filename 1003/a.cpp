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
	vector<int> fibo;
	for(int i=0;i<=40;i++) {
		if(unlikely(i == 0 || i == 1)) {
			fibo.push_back(1);
			continue;
		}
		fibo.push_back( fibo[i-1] + fibo[i-2] );
	}
	int N;
	cin >> N;
	for(int iter=0;iter<N;iter++) {
		int T;
		cin >> T;
		if(unlikely(T == 0)) {
			cout << "1" << " " << "0" << "\n";
			continue;
		} 
		if(unlikely(T == 1)) {
			cout << "0" << " " << "1" << "\n";
			continue;
		}
		cout << fibo[T-2] << " " << fibo[T-1] << "\n";
	}
	return 0;
}
