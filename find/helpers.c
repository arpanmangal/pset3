/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    // binary search
    
    if (n <= 0)
    {
        // value can't be in a non-existing array
        return false;
    }
   
    int mid = n / 2;
   
    if (values[mid] == value)
    {
        // checks if middle value is equal to "value"
        return true;
   }
   else if (values[mid] > value)  
    {
        // searches the array left of middle value
        return search (value, values, mid);
    }
    
   else
    {
        // searches the array right of middle value
        return search(value, values + mid + 1, n - mid - 1);
   }
}

// swapping function
void swap(int *num1, int *num2)
{
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    // sorting using bubble sort
    int phase, i;
    for (phase = 0; phase < n - 1; phase++)
    {
        for (i = 0; i < n - phase - 1; i++)
        {
            if (values[i] > values[i + 1])
            {
                swap (&values[i], &values[i + 1]);
            }
        }
    }
    return;
}