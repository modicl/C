#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char a = get_char("Estas de acuerdo? ");
    if (a == 'Y' || a == 'y')
    {
        printf("Acabas de aclarar que estas de acuerdo.\n");
    }
    else if (a == 'N' || a == 'n')
    {
        printf("Acabas de rechazar el acuerdo.\n");
    }
}