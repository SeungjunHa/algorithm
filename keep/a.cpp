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

typedef struct __pos {
	int row;
	int col;
	int step;
}POS;

struct compare {
	bool operator()(const POS& s1, const POS& s2) 
	{
		if(s1.step == s2.step) {
			if(s1.row == s2.row)
				return s1.col > s2.col;
			return s1.row > s2.row;	
		}
		return s1.step > s2.step;
	}
};

int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<POS, vector<POS>, compare> pq;
	for(int i=0;i<10;i++) {
		POS p;
		p.row = rand() % 3;
		p.col = rand() % 3;
		p.step = rand() % 3;
		printf("%d %d %d\n", p.row, p.col, p.step);
		pq.push(p);
	}

	for(int i=0;i<10;i++) {
		POS a = pq.top();
		printf("Top : %d %d %d %ld\n", a.row, a.col, a.step, pq.size());
		pq.pop();
	}
	return 0;
}






