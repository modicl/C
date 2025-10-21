#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x = get_int("Cuanto vale x? ");
    int y = get_int("Cuanto vale y? ");

    if (x < y)
    {
        printf("X que vale %d, es menor a Y que vale %d!\n", x, y);
    }
    else if (x > y)
    {
        printf("X que vale %d, es mayor a Y que vale %d!\n", x, y);
    }
    else
    {
        printf("X que vale %d, es igual a Y que vale %d!\n", x, y);
    }
}