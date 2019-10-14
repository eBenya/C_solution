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
/* Find Bug! If write 1-st argument how text, program do not write
random numbers. Program runs to ends.
    */
    // TODO: check numbers of arguments you entered
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // TODO: convert argv[1] how string to int
    int n = atoi(argv[1]);
    //Correction of the deffect associated with first argument
    //if(n == 0) printf("You entered 0 or text as first argument\n");

    // TODO: if entered two arguments then psevdogenerator generate
    //numbers depending on the argv[2]. If argv[2] entered as text(not a
    //number), srand genering number as argv[2] == 0.
    //else generate numbers depending on the current time(time(NULL))
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // TODO: write all generic numbers on the screen
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}