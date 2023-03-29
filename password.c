// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool lowerletter = false;
    bool upperletter = false;
    bool numbercheck = false;
    bool symbolcheck = false;
    bool finalcheck = false;

    for (int i = 0 ; i < strlen(password); i++ )
    {
        if (islower(password[i]))
        {
            lowerletter = true;
        }
        if (isupper(password[i]))
        {
            upperletter = true;
        }
        if (isalnum(password[i]))
        {
            numbercheck = true;
        }
        if (ispunct(password[i]))
        {
            symbolcheck = true;
        }
        printf("chqueando.. %c\n",password[i]);
    }

    if ( (lowerletter) && (upperletter) && (numbercheck) && (symbolcheck) )
        {
            finalcheck = true;
        }

    return finalcheck;
}
