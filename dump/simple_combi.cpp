#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
 
int n, rr, cnt = 0;
int arr[20];
 
void DFS(int depth, int r)
{
	int i;
 
	if (rr == depth) {
		printf("Current : [");
		for (i = 0; i < depth; i++)
			printf("%d,", arr[i]);
		printf("]\n");
        cnt++;
		return;
    }
	for(i=r; i<n; i++) {
		arr[depth] = i;
		DFS(depth+1, i+1);
	}
}
 
int main(void)
{
    scanf("%d %d", &n, &rr);
    
    DFS(0, 0);
 
    printf("%d\n", cnt);
 
    return 0;
}
