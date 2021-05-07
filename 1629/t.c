
#include <stdio.h>
int expo_alg(int a, int b, int n)
{
    int result = 1;

    while(b)
   {
      if(b & 1)
      {
         result = (result * a) % n ;
      }
       b /= 2;   
       a  = (a * a) % n ;
   }
   return result;
}

int main(void)
{
	int result = expo_alg(21474836,12312312,13131313);
	printf("%d\n", result);
}
