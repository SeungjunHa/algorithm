#include <stdio.h>

int main()
{
	int matrix[6][6];
	int rotate_matrix[2][2];

	for(int i=0;i<6;i++) 
		for(int j=0;j<6;j++) 
			matrix[i][j] = i*6+j;
		
	for(int i=2;i<4;i++) 
		for(int j=4;j<6;j++) 
			rotate_matrix[(j-4)][5-i-2] = matrix[i][j];
		
	for(int i=0;i<6;i++) {
		for(int j=0;j<6;j++) 
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
	printf("asdfasdfa\n");
	for(int i=0;i<2;i++) {
		for(int j=0;j<2;j++) 
			printf("%d ", rotate_matrix[i][j]);
		printf("\n");
	}

	
}
