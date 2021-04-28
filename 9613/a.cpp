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
static inline 
unsigned long long gcd(unsigned long long a, unsigned long long b) 
{
	return b ? gcd(b, a%b) : a;
}
int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for(int iter=0;iter<t;iter++) {
		unsigned int n;
		cin >> n;
		vector<unsigned long long> arr(n, 0);
		for(int i=0;i<n;i++) 
			cin >> arr[i];
	
		unsigned long long result = 0;	
		for(int i=0;i<n-1;i++) 
			for(int j=i+1;j<n;j++) 
				result += gcd(arr[i], arr[j]);
			
		cout << result << "\n";
		
	}
	return 0;
}
