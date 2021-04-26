#include <cstdio>
#include <vector>
#include <queue>

int n;
typedef struct __cube {
	char color[3][3];
}CUBE;

CUBE cube[6];

char init_color[6] = { 'w', 'r', 'y', 'o', 'g', 'b' };
void rotate_matrix_inverse(char matrix[3][3])
{
	char cmatrix[3][3];
	cmatrix[0][0] = matrix[0][2];
	cmatrix[0][1] = matrix[1][2];
	cmatrix[0][2] = matrix[2][2];
	cmatrix[1][0] = matrix[0][1];
	cmatrix[1][1] = matrix[1][1];
	cmatrix[1][2] = matrix[2][1];
	cmatrix[2][0] = matrix[0][0];
	cmatrix[2][1] = matrix[1][0];
	cmatrix[2][2] = matrix[2][0];
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			matrix[i][j] = cmatrix[i][j];	

}
void rotate_matrix(char matrix[3][3])
{
	char cmatrix[3][3];
	cmatrix[0][0] = matrix[2][0];
	cmatrix[0][1] = matrix[1][0];
	cmatrix[0][2] = matrix[0][0];
	cmatrix[1][0] = matrix[2][1];
	cmatrix[1][1] = matrix[1][1];
	cmatrix[1][2] = matrix[0][1];
	cmatrix[2][0] = matrix[2][2];
	cmatrix[2][1] = matrix[1][2];
	cmatrix[2][2] = matrix[0][2];
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			matrix[i][j] = cmatrix[i][j];	
}
void cycle_right_plus()
{
	char temp[3];
	for(int i=0;i<3;i++)
		temp[i] = cube[0].color[i][2];
	for(int i=0;i<3;i++)
		cube[0].color[i][2] = cube[1].color[i][2];
	for(int i=0;i<3;i++)
		cube[1].color[i][2] = cube[2].color[i][2];
	for(int i=0;i<3;i++)
		cube[2].color[2-i][2] = cube[3].color[i][0];
	for(int i=0;i<3;i++)
		cube[3].color[2-i][0] = temp[i];
	rotate_matrix(cube[5].color);
}
void cycle_left_plus()
{
	char temp[3];
	for(int i=0;i<3;i++)
		temp[i] = cube[0].color[i][0];
	for(int i=0;i<3;i++)
		cube[0].color[i][0] = cube[3].color[2-i][2];
	for(int i=0;i<3;i++)
		cube[3].color[2-i][2] = cube[2].color[i][0];
	for(int i=0;i<3;i++)
		cube[2].color[i][0] = cube[1].color[i][0];	
	for(int i=0;i<3;i++)
		cube[1].color[i][0] = temp[i];
	rotate_matrix(cube[4].color);
}
void cycle_upper_plus()
{
	char temp[3];
	for(int i=0;i<3;i++)
		temp[i] = cube[1].color[0][i];
	for(int i=0;i<3;i++)
		cube[1].color[0][i] = cube[5].color[0][i];
	for(int i=0;i<3;i++)
		cube[5].color[0][i] = cube[3].color[0][i];
	for(int i=0;i<3;i++)
		cube[3].color[0][i] = cube[4].color[0][i];
	for(int i=0;i<3;i++)
		cube[4].color[0][i] = temp[i];
	rotate_matrix(cube[0].color);
}
void cycle_down_plus()
{
	char temp[3];
	for(int i=0;i<3;i++)
		temp[i] = cube[1].color[2][i];
	for(int i=0;i<3;i++)
		cube[1].color[2][i] = cube[4].color[2][i];
	for(int i=0;i<3;i++)
		cube[4].color[2][i] = cube[3].color[2][i];
	for(int i=0;i<3;i++)
		cube[3].color[2][i] = cube[5].color[2][i];
	for(int i=0;i<3;i++)
		cube[5].color[2][i] = temp[i];
	rotate_matrix(cube[2].color);
}
void cycle_front_plus() 
{
	char temp[3];
	for(int i=0;i<3;i++)
		temp[i] = cube[0].color[2][i];
	for(int i=0;i<3;i++)
		cube[0].color[2][i] = cube[4].color[2-i][2];
	for(int i=0;i<3;i++)
		cube[4].color[i][2] = cube[2].color[0][i];
	for(int i=0;i<3;i++)
		cube[2].color[0][i] = cube[5].color[2-i][0];
	for(int i=0;i<3;i++)
		cube[5].color[i][0] = temp[i];
	rotate_matrix(cube[1].color);
}
void cycle_back_plus()
{
	char temp[3];
	for(int i=0;i<3;i++)
		temp[i] = cube[0].color[0][i];
	for(int i=0;i<3;i++)
		cube[0].color[0][i] = cube[5].color[i][2];
	for(int i=0;i<3;i++)
		cube[5].color[i][2] = cube[2].color[2][2-i];
	for(int i=0;i<3;i++)
		cube[2].color[2][i] = cube[4].color[i][0];
	for(int i=0;i<3;i++)
		cube[4].color[2-i][0] = temp[i];
	rotate_matrix(cube[3].color);
}
void cycle(char s, char c)
{
	if(s == 'R') {
		if(c == '+') {
			cycle_right_plus();	
		} else {
			cycle_right_plus();	
			cycle_right_plus();	
			cycle_right_plus();	
		}
	}
	if(s == 'L') {
		if(c == '+') {
			cycle_left_plus();
		} else {
			cycle_left_plus();
			cycle_left_plus();
			cycle_left_plus();
		}
	}
	if(s == 'U') {
		if(c == '+') {
			cycle_upper_plus();
		} else {
			cycle_upper_plus();
			cycle_upper_plus();
			cycle_upper_plus();
		}
	}
	if(s == 'D') {
		if(c == '+') {
			cycle_down_plus();
		} else {
			cycle_down_plus();
			cycle_down_plus();
			cycle_down_plus();
		}
	}
	if(s == 'F') {
		if(c == '+') {
			cycle_front_plus();
		} else {
			cycle_front_plus();
			cycle_front_plus();
			cycle_front_plus();
		}
	}
	if(s == 'B') {
		if(c == '+') {
			cycle_back_plus();
		} else {
			cycle_back_plus();
			cycle_back_plus();
			cycle_back_plus();
		}
	}
}
int main()
{
	scanf("%d", &n);
	for(int i=0;i<6;i++) 
		for(int j=0;j<3;j++) 
			for(int k=0;k<3;k++) 
				cube[i].color[j][k] = init_color[i];

	/*for(int i=0;i<6;i++) 
		for(int j=0;j<3;j++) {
			for(int k=0;k<3;k++) 
				printf("%c", cube[i].color[j][k]);
			printf("\n");
		}*/

	int temp;
	for(int iter=0;iter<n;iter++) {
		scanf("%d", &temp);
		for(int j=0;j<temp;j++) {
			char s[100];
			scanf("%s ", s);
			cycle(s[0], s[1]);
		}
		for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) 
				printf("%c", cube[0].color[i][j]);
			printf("\n");
		}
		for(int t=0;t<6;t++) 
			for(int j=0;j<3;j++) 
				for(int k=0;k<3;k++) 
					cube[t].color[j][k] = init_color[t];
	}	
	return 0;
}
