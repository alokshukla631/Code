#include "stdio.h"

#define N 10

int HCF(int num1, int num2)
{
   if(num2 == 0)
   {
      return num1;
   }
   
   return HCF(num2, num1%num2);
}

int LCM(int num1, int num2)
{
   int temp = 0;
   if(num1 < num2)
   {
      temp = num1;
      num1 = num2;
      num2 = temp;
   }
   return (num1*num2)/HCF(num1, num2);
}

int LCM_N_Numbers(int a[])
{
   int i = 0;
   for(i=0; i<N-1; i++)
   {
      a[i+1] = LCM(a[i],a[i+1]);
   }
   
   return a[i];
}

int main()
{
   int a[] = {1,2,3,4,5,6,7,8,9,10};
   printf("LCM of 10 Numbers = %d",LCM_N_Numbers(a));
   return 0;
}