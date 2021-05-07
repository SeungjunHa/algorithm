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

int dp[501][501];
int sum[501];
int arr[501];
int min_k[501][501];

int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;

	for(int iter=0; iter<N; iter++) {
		int result = 0;
		int num;
		cin >> num;
		for(int i=0;i<num;i++) 
			cin >> arr[i];

		for(int i=1;i<num+1;i++) {
			sum[i] = arr[i-1] + sum[i-1];	
			min_k[i][i] = i;
		}
		for(int i=num-2; i>=0; i--) {
			for(int j=i+1; j<num; j++) {
				int row = i;
				int col = j;
				int diff = sum[col+1] - sum[row];
				dp[row][col] = INT_MAX;		
				for(int t=min_k[row][col-1]; t<=min_k[row+1][col]; t++) {
					if(dp[row][col] > dp[row][t]+dp[t+1][col]) {
						dp[row][col] = dp[row][t]+dp[t+1][col];
						min_k[row][col] = t;
					}
				}
				dp[row][col] += diff;
			}
		}
		result = dp[0][num-1];
		cout << result << "\n";
#if 0
		/* 
			배열 접근을 할 때 VA를 연속적으로 접근해야 하는 것의 중요성... 
			이 부분은 4476ms걸리고 위의 코드는 1028ms걸림
		*/
		int k = 1;	
		for(int i=0;i<num;i++) {
			for(int j=0;j<num-k;j++) {
				int row = j;
				int col = j+k;
				int diff = sum[col+1] - sum[row];
				dp[row][col] = INT_MAX;
				
				for(int t=min_k[row][col-1]; t<=min_k[row+1][col]; t++) {
					if(dp[row][col] > dp[row][t]+dp[t+1][col]) {
						dp[row][col] = dp[row][t]+dp[t+1][col];
						min_k[row][col] = t;
					}
				}
				dp[row][col] += diff;
			}
			k++;
		}
		result = dp[0][num-1];
		cout << result << "\n";
#endif
	}
	return 0;
}
