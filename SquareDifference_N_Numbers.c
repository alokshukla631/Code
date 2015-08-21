#include "stdio.h"

#define N 100

int SquareDifference(int a[])
{
   int i = 0, b[N] = {0};
   int sumOfNumbers = 0;
   int sumOfSquares = 0;
   
   for(i=0; i<N; i++)
   {
      b[i] = a[i]*a[i];
   }
   
   for(i=0; i<N; i++)
   {
      sumOfNumbers += a[i];
      sumOfSquares += b[i];
   }
   
   return ((sumOfNumbers*sumOfNumbers) - sumOfSquares);
}
int main()
{
   int a[N];
   int i = 0;
   for(i=0; i<N; i++)
   {
      a[i] = i+1;
   }
   printf("diff of square of sum of n numbers and sum of sqaure of n numbers = %d\n",SquareDifference(a));
   return 0;
}