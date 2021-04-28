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
void print_empty(int start_row, int start_col, int N, vector<vector<char>> star)
{

}
static inline
void print_stars(int start_row, int start_col, int N, vector<vector<char>> star)
{
	if(N == 3) {
		int row_end = start_row + N;
		int col_end = start_col + N;
		for(int i=start_row;i<row_end;i++) {
			for(int j=start_col;j<col_end;j++) {
				if(i == j && i == start_row+1)
					star[i][j] = ' ';
				else
					star[i][j] = '*';
			}
		}
	} else {
		print_stars(start_row, start_col
	}
}
int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<vector<char>> star(N, vector<char>(N, 0));
	int index = N/3;	
	for(int i=0;i<N;i+=index) {
		for(int j=0;j<N;j+=index) {
			if(i == j && i == N/3) 
				print_empty(i, j, N, star);
			else
				print_stars(i, j, N, star);
		}
		cout << "\n";
	}
	return 0;
}
