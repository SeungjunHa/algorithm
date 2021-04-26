#include <cstdio>
#include <vector>
#include <queue>

// 0 : N극
// 1 : S극

// 1  : 시계 방향 회전
// -1 : 반시계 방향 회전
char wheel[4][8];
int cycle[100][2];
int K;
// 톱니바퀴 A를 회전할 때, 
// 그 옆에 있는 톱니바퀴 B와 서로 맞닿은 톱니의 극이 다르다면, 
// B는 A가 회전한 방향과 반대방향으로 회전하게 된다. 

void print_wheel()
{
	for(int i=0;i<4;i++) {
		for(int j=0;j<8;j++)
			printf("%c", wheel[i][j]);
		printf("\n");
	}
}
void cycling(int i, bool clock)
{
	char temp;
	if(clock) {
		temp = wheel[i][7];
		for(int j=7;j>=1;j--)
			wheel[i][j] = wheel[i][j-1];
		wheel[i][0] = temp;
	} else {
		temp = wheel[i][0];
		for(int j=0;j<7;j++)
			wheel[i][j] = wheel[i][j+1];
		wheel[i][7] = temp;
	}
}

void simulation(int n)
{
	int target_wheel = cycle[n][0];
	bool is_clock = !!cycle[n][1];
	bool before_clock = is_clock;

	bool attach[3]; // true면 같이 돌아야함 (반대로)

	for(int i=0;i<3;i++) 
		attach[i] = (wheel[i][2] == wheel[i+1][6]) ? false : true;

	// target_wheel이 0번이면 1,2,3 순서로 체크
	// target_wheel이 1번이면 0,3 체크하고 3이 돌면 4도 체크
	// target_wheel이 2번이면 1,3 체크하고 1이 돌면 0도 체크
	// target_wheel이 4번이면 3,2,1 순서로 체크
	cycling(target_wheel, is_clock);
	if(target_wheel == 0) {
		for(int i=1;i<4;i++) {
			if(!attach[i-1]) 
				break;
			before_clock = !before_clock;
			cycling(i, before_clock);
		}
	}
	if(target_wheel == 1) {
		if(attach[0])
			cycling(0, !is_clock);
		for(int i=2;i<4;i++) {
			if(!attach[i-1]) 
				break;
			before_clock = !before_clock;
			cycling(i, before_clock);
		}
	}
	if(target_wheel == 2) {
		if(attach[2])
			cycling(3, !is_clock);
		for(int i=1;i>=0;i--) {
			if(!attach[i])
				break;
			before_clock = !before_clock;
			cycling(i, before_clock);
		}
	}
	if(target_wheel == 3) {
		for(int i=2;i>=0;i--) {
			if(!attach[i])
				break;
			before_clock = !before_clock;
			cycling(i, before_clock);
		}
	}	
}
int main()
{
	int s;
	for(int i=0;i<4;i++) {
		for(int j=0;j<8;j++) 
			scanf("%c", &wheel[i][j]);
		getchar();
	}
	scanf("%d", &K);
	for(int i=0;i<K;i++)
		scanf("%d %d", &cycle[i][0], &cycle[i][1]);
	for(int i=0;i<K;i++) {
		cycle[i][0] -= 1;
		cycle[i][1] += 1;
	}

		
	for(int i=0;i<K;i++) 
		simulation(i);

	int sum = 0;
	for(int i=0;i<4;i++) 
		if(wheel[i][0] == '1') 
			sum += (1 << i);
	
	printf("%d\n", sum);
	return 0;
}








