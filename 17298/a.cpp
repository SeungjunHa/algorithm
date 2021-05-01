#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

#define likely(x) __builtin_expect((x), 1)
#define unlikely(x) __builtin_expect((x), 0)

typedef struct __pair {
	int value;
	int index;
}Pair;

int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> num(N, 0);
	for(int i=0;i<N;i++) 
		cin >> num[i];
	
	vector<Pair> stack;
	vector<int> answer(N, -1);
	for(int i=0;i<N;i++) {
		int target = num[i];
		if(stack.empty()) {
			stack.push_back( {target, i} );
			continue;
		}
		Pair top = stack.back();
		if(top.value >= target) {
			stack.push_back( {target, i} );
			continue;
		}
		stack.pop_back();
		answer[top.index] = target;
		while(true) {
			if(stack.empty())
				break;
			top = stack.back();
			if(target > top.value) {
				answer[top.index] = target;
				stack.pop_back();
			} else
				break;
		}
		stack.push_back( {target, i} );
	}
	int stack_size = stack.size();
	if(stack_size != 0) {
		for(int i=0; i<stack_size; i++) {
			if(i == 0 || i == stack_size-1) {
				answer[stack[i].index] = -1;
				continue;
			}
			if(stack[i+1].value > stack[i].value)
				answer[stack[i].index] = stack[i+1].value;
		}
	}
	for(int i=0;i<N;i++) 
		cout << answer[i] << " ";
	cout << "\n";
	return 0;
}
