#include <stdio.h>

void change(int arr[5])
{
	arr[3] = 10;
}
int main()
{
	int arr[5] = {1,2,3,4,5};
	int arr2[5];
	for(int i=0;i<5;i++)
		arr2[i] = arr[i];
	printf("%d %d \n", arr[3], arr2[3]);
	change(arr);
	printf("%d %d \n", arr[3], arr2[3]);
}
