#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define DIGITS 3

// return a^b
int pow1(int a, int b)
{
	int i = 0;
	float num = 1;
	for(i=0; i<b; i++)
	{
		num = num*a;
	}
	return num;
}

void setChar(int num, char *str, int i)
{
    //printf("IsPalindrome str = %d\n",str);
    str[i] = num + '0';
    //printf("IsPalindrome char = %c\n",str[i]);
    
}

void Itoa(int num, char *str)
{
    int p = 0, q = 0, r = 0;
    int i = 0;
    //printf("IsPalindrome str = %d\n",str);
    
    while(num)
    {
        p = (num/10)*10;
        q = num - p;
        setChar(q, str, i); // put q converted to character in str[i]
        num = num/10;
        i++;
    }
    str[i] = '\0';
}

int IsPalindrome(int num)
{
    char *str = (char *) malloc(2*DIGITS);
    //printf("IsPalindrome num = %d\n",num);
    Itoa(num, str);
    int len = strlen(str);
    
    //printf("IsPalindrome str = %s\n",str);
    int start = 0;
    int end = len-1; 
    
    while(start < end)
    {
        if(str[start] != str[end])
        {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}


int MaxProduct()
{
    int min = pow1(10,DIGITS-1);
    int max = 0;
    int i = 0;
    int num1 = 0, num2 = 0;
    int maxProduct = 0;
    
    for(i=0; i<DIGITS; i++)
    {
        max = max*10 + 9;
    }
    
    for(num1=max; num1 >= min; num1--)
    {
        for(num2=num1-1; num2 >= min; num2--)
        {
            if(IsPalindrome(num1*num2))
            {
                maxProduct = maxProduct < num1*num2 ? num1*num2 : maxProduct;
            }
        }
    }

    return maxProduct;
}

int main()
{
    printf("maxProduct = %d\n",MaxProduct());
    return 0;
}

