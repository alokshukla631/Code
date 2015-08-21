#include "stdio.h"

#define N 20

double HCF(double num1, double num2)
{
    printf("num1 = %f and num2 = %f\n",num1, num2);
   if(num2 == 0)
   {
        printf("hcf = %f\n",num1);
      return num1;
   }
    while(num1 > 0)
    {
        num1 = num1 - num2;
    }
    num1 = (num1 == 0) ? 0 : (num1 + num2);

   return HCF(num2, num1);
}

double LCM(double num1, double num2)
{
   double temp = 0;
   if(num1 < num2)
   {
      temp = num1;
      num1 = num2;
      num2 = temp;
   }
   return (num1*num2)/HCF(num1, num2);
}

double LCM_N_Numbers(double a[])
{
   int i = 0;
   for(i=0; i<N-1; i++)
   {
      a[i+1] = LCM(a[i],a[i+1]);
      printf("a[%d] = %f\n",i+1, a[i+1]);
   }
   
   return a[i];
}

int main()
{
   double a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
   printf("LCM of 10 Numbers = %f",LCM_N_Numbers(a));
   return 0;
}