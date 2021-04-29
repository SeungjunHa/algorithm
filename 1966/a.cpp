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

int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for(int iter=0;iter<N;iter++) {
		int result = 0;
		int M, Index;
		cin >> M >> Index;
		queue <pair<int, int>> q;
		priority_queue <int, vector<int>> pq;

		vector<int> arr(M, 0);
		for(int index=0;index<M;index++) {
			int priority;
			cin >> priority;
			q.push( {index, priority} );
			pq.push(priority);
		}
		
		int count = 0;
		while(!q.empty()) {
			int max_priority = pq.top(); 
			pair<int, int> n = q.front(); q.pop();

			if(n.second == max_priority) {
				count++;
				pq.pop();
				if(n.first == Index) {
					cout << count << "\n";
					break;
				}
			} else {
				q.push(n);
			}
		}
	}
	return 0;
}
