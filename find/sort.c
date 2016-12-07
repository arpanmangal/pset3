#include <stdio.h>
#include <cs50.h>


void swap (int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    // sorting using bubble sort
    int phase, i;
    for (phase = 0; phase < n-1; phase++)
    {
        for (i = 0; i < n-phase-1 ; i++)
        {
            if (values[i] > values[i+1])
            {
                //printf("\nswapping %d %d\n",values[i],values[i+1]);
                swap (&values[i], &values[i+1]);
            }
        }
    }
    return;
}

int main()
{
    int arr[] = {1, 4, 7, 3, 5, 1, 2};
    int i;
    sort (arr, 7);
    for (i = 0; i < 7; i++)
    {
        printf ("%d ", arr[i]);
    }
}