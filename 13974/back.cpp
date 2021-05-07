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

int dp[5001][5001];
int sum[5001];
int arr[5001];
int min_k[5001][5001];

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
		int k = 1;	
		for(int i=0;i<num;i++) {
			for(int j=0;j<num-k;j++) {
				int row = j;
				int col = j+k;
				int diff = sum[col+1] - sum[row];
				dp[row][col] = INT_MAX;
				
/* Fast Version(8ms) : Search small part 
	https://onedaycoding.tistory.com/82
	해당 링크를 참고했는데, 특별한 경우에 DP를 Optimize 할 수 있다 한다.
	조건 1)
		점화식이 dp[i][j] = min(dp[i][k], dp[k][j]) + C[i][j] 의 형태일 때
	조건 2) 사각부등식
		- C[a][c] + C[b][d] <= C[a][d] + C[b][c] (a <= b <= c <= d)
	조건 3) 단조 증가
		- C[b][c] <= C[a][d] (a <= b <= c <= d)

	증명-
		본 문제에서 C[a][c]가 의미하는건 a에서 c까지 구간 합이다.
		a, b, c, d가 증가하는 값들이기 때문에, 
		C[a][d] = C[a][b] + C[b][c] + C[c][d] 등으로 풀어 쓸 수 있다.
		조건1,3는 자명하고, 조건2는 위 문장처럼 풀면 양 변이 같은 값이라 성립한다.

	위 조건을 모두 성립할 때,
		num[i][j-1] <= num[i][j] <= num[i+1][j]
		(num[i][j] 는 dp[i][k] + dp[k][j] 가 최소가 되게 하는 k(i < k < j) 값)
*/
				for(int t=min_k[row][col-1]; t<=min_k[row+1][col]; t++) {
					if(dp[row][col] > dp[row][t]+dp[t+1][col]) {
						dp[row][col] = dp[row][t]+dp[t+1][col];
						min_k[row][col] = t;
					}
				}
				dp[row][col] += diff;
#if 0
				/* Slow Version(144ms) : Search all t between row, col */
				for(int t=row;t<col;t++) 
					dp[row][col] = min(dp[row][col], dp[row][t] + dp[t+1][col] + diff);
				
#endif
			}
			k++;
		}
		result = dp[0][num-1];
		cout << result << "\n";
	}
	return 0;
}
