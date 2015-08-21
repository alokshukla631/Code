#include <stdafx.h>
int count;

void permute(int start, int end, char a[])
{
    int i=0, j=0;
    char temp;
    if(start == end)
    {
        for(j=0; j<end+1; j++)
        {
            printf("%c,",a[j]);
        }
        printf("\n");
        count++;
        return;
    }
        

    for(i=start; i<=end; i++)
    {
        temp = a[start];
        a[start] = a[i];
        a[i] = temp;
        permute(start+1, end, a); 
        temp = a[start];
        a[start] = a[i];
        a[i] = temp;
    }
}
int main()
{
    char a[4] = {'a','b','c'};
    permute(0, 2, a);
    printf("count:%d\n",count);
    return 0;
}