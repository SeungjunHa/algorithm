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

	int A, B;
	string tmp;
	int result[10] = { 0, };
	
	cin >> A >> B;
	A *= B;
	cin >> B;
	A *= B;

	tmp = to_string(A);
	for(int i=0;i<tmp.size();i++) 
		result[tmp[i]-'0']++;
	
	for(int i=0;i<10;i++) 
		cout << result[i] << endl;

	return 0;
}
