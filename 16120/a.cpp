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
	cout << str << endl;
	char temp[4] = { 'P', 'P', 'A', 'P' };
	for(int i=0;i<str.size();i++) {
		printf("%d %c\n", i, str[i]);
		if(str[i] == 'P') {
			int remain = 0, cnt = 0, flag = 1, start = i;
			while(1) {
				if(str[start+remain] == 'U')
					start++;
				printf("[%d %c] : [%d %c]\n", 
						start+remain, str[start+remain], remain, temp[remain]);
				if(str[start+remain] == temp[remain]) 
					remain++;
				else
					flag = 0;
				if(remain == 4) 
					break;
				cnt++;
				if(cnt > 5)
					break;
			}
			if(flag) {
				for(int j=i+1;j<i+4;j++) {
					str[j] = 'U';
				}
			}
		}
	}


	return 0;
}
