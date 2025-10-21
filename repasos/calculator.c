#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long x = get_long("Valor de x? ");
    long y = get_long("Valor de y? ");
    printf("El valor total de la suma es %ld.\n", x + y);
}
