#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hourweeks[weeks];

    for (int i = 0 ; i < weeks ; i++)
    {
        hourweeks[i] = get_int("Week %i hours: ",i);

    }

    printf("Your hours inputted where:\n");

    for (int i = 0 ; i < weeks ; i++)
    {
        printf("%i  ",hourweeks[i]);
    }
    printf("\n");

    char prompto = get_char("You want the average of hours or the total? Type 'T' for total or 'A' for your average. ");
    char typecalc = toupper(prompto);
    int sumhours = 0;
    float avghours = 0.0;

    if (typecalc == 84)
    {
        for (int i = 0 ; i < weeks ; i++)
        {
            sumhours += hourweeks[i];
        }
        printf("Your total hours were : %i\n",sumhours);
    }

    else if (typecalc == 65)
    {
        for (int i = 0 ; i < weeks ; i++)
        {
            sumhours += hourweeks[i];
        }
        avghours = (float) sumhours / (float) weeks ;
        printf("Your average hours were: %.2f\n", avghours);
    }

}
