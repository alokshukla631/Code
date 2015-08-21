#include <stdafx.h>

int partition(int a[], int start, int end)
{
    int i = start;
    int j = end;
    int part = a[start];
    int temp = 0;

    while(i < j)
    {
        while(a[i] <= part)
        {
            i++;
        }

        while(a[j] > part)
        {
            j--;
        }

        if(i < j)
        {
            // swap a[i] and a[j]
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    // swap a[start] and a[j]
    temp = a[start];
    a[start] = a[j];
    a[j] = temp;

    return j;
}

void quickSort(int a[], int start, int end)
{
    int part = 0;
    if(start < end)
    {
        part = partition(a, start, end);

        quickSort(a, start, part-1);
        quickSort(a, part+1, end);
    }
}

void merge(int a[], int b[], int start, int mid, int end)
{
    int i = start;
    int j = mid+1;
    int k = 0;

    // fill which ever is small number in the array b
    while(i <= mid && j <= end)
    {
        if(a[i] < a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }


    // fill the left numbers in array to b
    if(i <= mid)
    {
        while(i <= mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
    }
    else if(j <= end)
    {
        while(j <= end)
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }

    k = 0;
    // copy sorted data from b to a
    while(start <= end)
    {
        a[start] = b[k];
        start++;
        k++;
    }
}

void mergeSort(int a[], int b[], int start, int end)
{
    int mid = 0;
    if(start < end)
    {
        mid = (start+end)/2;

        mergeSort(a, b, start, mid);
        mergeSort(a, b, mid+1, end);

        merge(a, b, start, mid, end);
    }
}

void createHeap(int a[], int len)
{
    int i = 0, j = 0;
    int temp = 0;

    for(i=0; i<len; i++)
    {
        j = i;
        while(j/2 && a[j] > a[j/2])
        {
            // swap a[i] and a[i/2]
            temp = a[j];
            a[j] = a[j/2];
            a[j/2] = temp;
            j = j/2;
        }
    }
}

void adjust(int a[], int len)
{
    // find the right place for a[1]
    int i = 1;
    int j = 2*i;
    int temp = 0;

    while(j <= len)
    {
        if((j+1) <= len)
        {
            j = a[j] > a[j+1] ? j : j+1; // let a[j] be the greater of a[j] and a[j+1]
        }
        if(a[j] > a[i])
        {
            // swap a[j] and a[i]
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
            i = j;
            j = 2*i;
        }
        else
        {
            // found right place for a[i]
            break;
        }
    }
}

void heapSort(int a[], int len)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    createHeap(a, len);
    for(i=0; i<len; i++)
    {
        printf("%d,",a[i]);
    }
    printf("\n");

    // sort now
    for(i=len-1; i > 0; i--)
    {
        // swap a[i] with a[1]
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;

        adjust(a, i-1);
        for(j=0; j<len; j++)
        {
            printf("%d,",a[j]);
        }
        printf("\n");
    }
}


//insertion sort sorts the list by taking one item at a time and placing it at its right
//position in the already sorted array
// example if the list is 65 32 11 25
// then first it will compare 65 and 32 and put 32 at 0th position and 65 at 1st position
// so the list will become 32 65 11 25
// now it will insert this 11 in the already sorted list 32 65
// so now it will put 11 at 0th position and the list will become 11 32 65 25, for this shifting will be required
void insertionSort(int a[], int len)
{
    int i = 0;
    int j = 0;
    int temp = 0;

    for(i=1; i<len; i++)
    {
        j = i;
        while(j > 0 && a[j] < a[j-1])
        {
            //swap a[j] and a[j-1]
            temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
            j--;
        }
    }
}

//selection sort, divides the list in two parts one having the sorted array and other unsorted
//runs the loop in unsorted list and swaps the smallest element in the unsorted array with the next place in sorted array
// increments sorted list by 1 and decrements unsorted list by 1
// initially sorted list has 0 elements and unsorted N
void selectionSort(int a[], int len)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    int smallest = 0;

    for(i=0; i<len; i++)
    {
        j = i;
        smallest = j;
        while(j < len)
        {
            if(a[j] < a[smallest])
            {
                smallest = j;
            }
            j++;
        }

        //swap a[i] and a[smallest]
        temp = a[i];
        a[i] = a[smallest];
        a[smallest] = temp;
    }
}



// needs some work still
void shellSort(int a[], int len)
{
    int gap = len;
    int i = 0;
    int temp = 0;
    int j = 0;

    for(gap = len/2; gap > 0; gap /=2)
    {
        for(i=gap; i < len; i++)
        {
            // compare a[i] and a[i-gap]
            //if(a[i] < a[i-gap])
            //{
            //    //swap
            //    temp = a[i];
            //    a[i] = a[i-gap];
            //    a[i-gap] = temp;
            //}
            for(j=i-gap; j >= 0 && a[j] > a[j+gap]; j=j-gap)
            {
                temp = a[i];
                a[i] = a[i-gap];
                a[i-gap] = temp;
            }
        }

        for(i=0; i<10; i++)
        {
            printf("%d,",a[i]);
        }
        printf("\n");
    }
}


int main()
{
    int a[] = {10,9,8,7,6,5,4,3,2,1};
    int b[10] = {0};
    int c[11] = {0,10,9,8,7,6,5,4,3,2,1}; // as in heap c[0] is not used
    int i = 0;
    //quickSort(a, 0, 9);
    //mergeSort(a, b, 0, 9);

    //heapSort(c, 11);

    //insertionSort(a, 10);

    //selectionSort(a, 10);

    shellSort(a, 10);

    for(i=0; i<10; i++)
    {
        printf("%d,",a[i]);
    }
    return 0;
}