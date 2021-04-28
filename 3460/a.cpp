#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define likely(x) __builtin_expect((x), 1)
#define unlikely(x) __builtin_expect((x), 0)

int T, N;

int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> T;


	for(int i=0;i<T;i++) {
		cin >> N;
		int mask = 1;
		int index = 0;
		while(true) {
			if((N & mask) == mask)
				cout << index << " ";
			mask <<= 1;
			index++;
			if(mask > N)
				break;
		}
		cout << "\n";
	}

	return 0;
}
