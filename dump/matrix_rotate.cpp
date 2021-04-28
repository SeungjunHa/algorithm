#include <iostream>
#include <vector>

using namespace std;

void print_matrix(vector<vector<int>> mat, int N, const char *s)
{	
	cout << s;
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++)
			cout << mat[i][j] << "\t";
		cout << "\n";
	}
}
int main()
{
	int N;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	vector<vector<int>> matrix(N, vector<int>(N, 0));
	vector<vector<int>> rotate_matrix(N, vector<int>(N, 0));
	cout << "Initailize (" << N << "x" << N << ") matrix\n\n";
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			matrix[i][j] = i*N+j;
	print_matrix(matrix, N, "Init Matrix\n");

	for(int i=0;i<N;i++) 
		for(int j=0;j<N;j++) 
			rotate_matrix[j][i] = matrix[N-1-i][j];			
	print_matrix(rotate_matrix, N, "After Clock 90\n");

	for(int i=0;i<N;i++) 
		for(int j=0;j<N;j++) 
			rotate_matrix[j][i] = matrix[i][N-1-j];
	print_matrix(rotate_matrix, N, "After Clockwise 90\n");

	for(int i=0;i<N;i++) 
		for(int j=0;j<N;j++) 
			rotate_matrix[j][i] = matrix[N-1-i][N-1-j];
	print_matrix(rotate_matrix, N, "After 180 Rotate\n");

	for(int i=0;i<N;i++) 
		for(int j=0;j<N;j++) 
			rotate_matrix[i][j] = matrix[i][N-1-j];
	print_matrix(rotate_matrix, N, "After Y-axis Symmetry\n");

	for(int i=0;i<N;i++) 
		for(int j=0;j<N;j++) 
			rotate_matrix[i][j] = matrix[N-1-i][j];
	print_matrix(rotate_matrix, N, "After X-axis Symmetry\n");

	for(int i=0;i<N;i++) 
		for(int j=0;j<N;j++) 
			rotate_matrix[i][j] = matrix[N-1-i][N-1-j];
	print_matrix(rotate_matrix, N, "After Origin Symmetry\n");


	return 0;
}
