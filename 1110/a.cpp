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

	string input, string1, string2;
	int tmp1, tmp2, num2;
	cin >> input;
	if(input.size() == 1) 
		input = '0' + input;
	string1 = input;

	int cnt = 0;
	while(1) {
		cnt++;
		if(string1.size() == 1) 
			string1 = '0' + string1;

		tmp1 = string1[0] - '0';
		tmp2 = string1[1] - '0';

		num2 = tmp1 + tmp2;
		num2 %= 10;

		string2 = to_string(num2);
		string2 = string1[1] + string2;
		
		if(string2.compare(input) == 0) 
			break;
		
		string1 = string2;
		string2.clear();
	}
	cout << cnt << endl;	

	return 0;
}
