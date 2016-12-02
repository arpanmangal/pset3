/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // ensures that the user enter proper number of command line arguments i.e. either 2 or 3 including ./generate
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // converts the second value of argv array from string to an integer and stores into n
    int n = atoi(argv[1]);

    // checks if optional seed is provided
    /* if it is provided it is passed to srand48 after converting to long int
          otherwise passes a new time_t object that represents the current time to srand48 */
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // generates that amount of random numbers equal to the number entered by the user 
    // drand48 returns float from 0.0 to 1.0 so multiplying it with LIMIT and converting to int gives int between 0 and LIMIT
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
