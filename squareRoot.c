#include <stdio.h>


// return a^b

float pow1(int a, int b)

{
    
	int i = 0;
    
	float num = 1;
    
	for(i=0; i<b; i++)
    
	{
        
		num = num*a;
    
	}
    
	return num;

}



//square root of num upto 'decimal' decimals
float squareRoot(float num, int decimal)

{
    
	float i = 0;
    
	int j = 0;
    
	for(j=0; j<(decimal+1); j++)
    
	{
        
		while((i*i) < num)
        
		{
            
			i = i + 1/pow1(10, j); // make sure that pow1 return float else in division it converts whole 1/pow1(10,j) to integer and as it is less than 1 so to 0
        
		}
        
		i = i - 1/pow1(10, j);
   	}
    
    
	return i;

}



int main()

{
    
	printf("%f\n",squareRoot(1.3,6));
    
	return 0;

}

