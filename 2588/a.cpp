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

	int num0, num1, num2, num3, num4;
	string input1, input2;
	cin >> input1 >> input2;

	num0 = stoi(input1);
	num1 = input2[2] - '0';
	num2 = input2[1] - '0';
	num3 = input2[0] - '0';

	num1 *= num0;
	num2 *= num0;
	num3 *= num0;
	num4 = num0 * stoi(input2);	

	cout << num1 << endl << num2 << endl << num3 << endl << num4 << endl;
	
	return 0;
}
