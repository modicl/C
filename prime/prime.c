#include <cs50.h>
#include <stdio.h>

int prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i) == 0)
        {
            printf("%i\n", i);
        }
    }
}

int prime(int number)
{
    // TODO
    int primestatus = 0;
    int primecounter = 0;
    for (int i = 1; i <= number -1; i++)
    {
        if (i == 1 && number == 1)
        {
            primecounter++;
        }
        else if(number%i != 0)
        {
            primecounter++;
        }
        return primecounter;
    }
    return primecounter;
}
