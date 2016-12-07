/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include<stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    int i;
    // check if n is valid
    if (n <= 0)
    {
        return false;
    }
    
    // use linear search
    for (i = 0; i < n; i++)
    {
        if (values[i] == value)
        {
            return true;
        }
    }
    return false;
}

// swapping function
void swap (int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * Sorts array of n values.
 */
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