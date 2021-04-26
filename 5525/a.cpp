#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
string str;

int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> str;
	int result = 0, i, j, flag = 1, start, end;
	int index = (N << 1) + 1;
	int last = str.length()-index+1;
	int sequence_map[N];
	for(i=0; i<last; i++) {
		if(str[i] == 'O')
			continue;
		int cnt = 0;
		while(str[i+1] == 'O' && str[i+2] == 'I') {
			i+=2;
			cnt++;
			if(cnt == N) {
				result++;
				cnt--;
			}
		}
	}
	cout << result << endl;

	return 0;
}
/*
I OI 문자열을 O(N^2)으로 계산하면 시간초과
OI 문자열이 등장하는 동안 result랑 같아질 때 까지 cnt++ 해주고, 만약 같아지면 cnt--
=> 이전에 등장했던 OI는 다시 안들리므로 O(N)만에 가능
*/
#if 0
		if(str[i] == 'I' && str[i+1] == 'O') {
			start = i+2;
			end = start + index - 3;
			for(j=start; j<end; j+=2) {
				if(str[j] == 'I' && str[j+1] == 'O') 
					continue;
				break;
			}
			if(j == end) {
				if(str[j] == 'I') {
					result++;
					i++;
				} else {
					i = j;
				}
			} else
				i = j;
		}
#endif
