#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Ask for starting population
    int starting;
    do
    {
        starting = get_int("What is the starting population of llamas? ");
    }
    while (starting <9);
    // Ask for ending population
    int ending;
    do
    {
        ending = get_int("What is the ending population of llamas? ");
    }
    while (ending < starting);
    // Declaring the years variable
    int years = 0;
    // Declaring the actual population in each cycle
    int currentpop = 0;
    // Declaring the net difference between death and born
    int net = 0;
    int finalpop = 0;

    while (finalpop < ending)
    {
        // We check first for the calculation of the year 0 so we use the starting number as base.
        if (finalpop < ending && years == 0)
        {
            float bornpop = ((float) starting / 3);
            float deathpop = ((float) starting / 4);
            net = (int) bornpop - (int) deathpop;
            finalpop = starting + net;
            years++;
        }
        // Once we reach year 0 we need to use finalpop as the base number.
        else if (finalpop < ending && years > 0)
        {
            float bornpop = ((float) finalpop / 3);
            float deathpop = ((float) finalpop / 4);
            net = (int) bornpop - (int) deathpop;
            finalpop = finalpop + net;
            years++;
        }

    }
    // Printing the final result of years needed.
    printf("Start size: %i \n",starting);
    printf("End size: %i \n",ending);
    printf("Years: %i \n",years);


}