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

	string input;
	cin >> input;

	string pre_alloc = "";
	for(int i=1;i<1000;i++) 
		pre_alloc+=to_string(i);
	
	int index1 = 0, index2 = 0;
	while(1) {
		char a = input[index1];
		char b = pre_alloc[index2];
		if(a == b) 
			index1++; 
		index2++;
		if(index1 == input.size())
			break;
		if(index2 == pre_alloc.size())
			break;
	}
	printf("Result : ");
	index2 -= 1;
	if(index2 < 9) {
		printf("%c\n", pre_alloc[index2]);
	} else if(index2 < 189){
		if(index2 % 2) 
			printf("%c%c\n", pre_alloc[index2], pre_alloc[index2+1]);
		else
			printf("%c%c\n", pre_alloc[index2-1], pre_alloc[index2]);
	} else {
		if(index2 % 3 == 0) 
			printf("%c%c%c\n", 
				pre_alloc[index2], pre_alloc[index2+1], pre_alloc[index2+2]);
		else if(index2 % 3 == 1)
			printf("%c%c%c\n", 
				pre_alloc[index2-1], pre_alloc[index2], pre_alloc[index2+1]);
		else if(index2 % 3 == 2)
			printf("%c%c%c\n", 
				pre_alloc[index2-2], pre_alloc[index2-1], pre_alloc[index2]);
	}
	return 0;
}







