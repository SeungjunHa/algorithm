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

bool compare(char a, char b) 
{
	return b < a;
}

int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string number;
	cin >> number;

	vector<char> arr;
	sort(number.begin(), number.end(), compare);
	unsigned long long three = 0;
	bool zero = false;
	
	for(int i=0;i<number.size();i++) {
		int temp = number[i] - '0';
		arr.push_back(number[i]);
		if(temp == 0)
			zero = true;
		else
			three += temp;
	}
	
	//string s(arr.begin(), arr.end());
	string s;
	for(char c : arr)
		s += c;
	if(!zero)
		cout << "-1" << endl;
	else {
		if((three % 3) == 0)
			cout << s << endl;
		else
			cout << "-1" << endl;
	}
	
	return 0;
}
