#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <omp.h>

#define SAFE
#ifdef SAFE
#define STRTOK(s, d, p) strtok_r(s, d, p);
#else
#define STRTOK(s, d, p) strtok(s, d);
#endif
	
int main()
{
    char s1[30] = "The Little Prince";
    char s2[30] = "He Big Maze";

	char *saveptr1;
	char *saveptr2;

	char *ptr1 = STRTOK(s1, " ", &saveptr1);
    char *ptr2 = STRTOK(s2, " ", &saveptr2);

	/* 
		NULL 대신 (ptr1+strlen(ptr1)+1) 하면 strtok으로도 가능
		NULL을 쓸거면 strtok_r을 통해서 saveptr을 저장해놔야 thread-safe
	*/
#pragma omp parallel for num_threads(2)
	for(int i=0;i<2;i++) {
		if(i == 0) {
			while (ptr1 != NULL) {
				printf("%s [%ld]\n", ptr1, strlen(ptr1));
				ptr1 = STRTOK(NULL, " ", &saveptr1);
				//ptr1 = STRTOK(ptr1+strlen(ptr1)+1, " ", &saveptr1);
			}
		} else {
			while(ptr2 != NULL) {
				printf("%s [%ld]\n", ptr2, strlen(ptr2));
		        ptr2 = STRTOK(NULL, " ", &saveptr2);
				//ptr2 = STRTOK(ptr2+strlen(ptr2)+1, " ", &saveptr2);
			}
		}
	} 

    return 0;
}
