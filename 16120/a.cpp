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

	string str;
	cin >> str;
	int cnt = 0;
	for(int i=0;i<str.size();i++) {
		if(str[i] == 'P') {
			cnt++;
			continue;
		}
		if(cnt >= 2 && str[i+1] == 'P') {
			cnt--;
			i++;
		} else {
			printf("NP\n");
			return 0;
		}
	}
	
	if(cnt == 1)
		printf("PPAP\n");
	else
		printf("NP\n");
	return 0;
}
