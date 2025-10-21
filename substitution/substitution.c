#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

bool keycheck(string text);
string cipherme(string key, string text);

int main(int argc, string argv[])
{
    while (argc != 2)
    {
        printf("You need to input a key, please try again rerunning './substitution <26 letter key>'.\n");
        return 1;
        break;
    }
    if ( keycheck(argv[1]) )
    {
        printf("Your key must have exactly 26 letters and no repeated letters.\n");
        return 1;
    }
    string cipher = argv[1];
    string plaintext = get_string("plaintext:");
    printf("ciphertext: %s\n", cipherme(cipher,plaintext));
}

bool keycheck(string text)
{
    // We initialize a count for every letter in an array of ints
    int lettercount[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int lettervalue = 0;
    int repeatedvalue = 0;
    bool notokay = false;
    bool lettercheck = false;
    bool repeatedcheck = false;
    for (int i = 0 ; i < strlen(text) ; i++ )
    {
        // We add to our lettercount ignoring upper or lower case
        if ( isalpha(text[i]) )
        {
            // We check if is upper we add to our letter count array
            if ( (isupper(text[i])) )
            {
                int index = 90 - (text[i]);
                lettercount[24-index+1] += 1;
            }
            // We check if it is lower and we add to our letter count array
            if ( (islower(text[i])) )
            {
                int index = 122 - (text[i]);
                lettercount[24-index+1] += 1;
            }
        }
        }
    // We sum all the quantity of every letter
    for (int i = 0 ; i < 26 ; i++)
    {
        lettervalue += lettercount[i];
    }
    // We display which letter is repeated ignoring its upper or lower status
    // We have to initialize a repeat counter to check if there is any repeated letter
    int repeated = 0;
    for (int i = 0 ; i < 26 ; i++)
    {
        if (lettercount[i] > 1)
        {
            printf("%c is repeated %i times.\n",65+i,lettercount[i]);
            repeated += 1;
        }
    }
    // We check if the total letters are 26 or not
    if (lettervalue != 26 )
    {
        lettercheck = true;
    }
    // We check if there are repeated letters
    if (repeated > 0)
    {
        repeatedcheck = true;
    }
    // Not optimal implementation, but if any of the "check" status are true, we set "notokay" to true
    // If everything would be fine "notokay" remains "false".
    if (repeatedcheck)
    {
        printf("You have repeated letters!, see previous message(s).\n");
        notokay = true;
    }

    if (lettercheck)
    {
        notokay = true;
        printf("You have entered %i letters.\n", lettervalue);
    }
    return notokay;
}

string cipherme(string key, string text)
{
    int cipherletter = 0;
    int textletter = 0;
    string finaltext = text;
    for (int i = 0 ;i < strlen(text); i++)
    {
        if ( isspace(text[i]) )
        {
            finaltext[i] = text[i];
        }
        if ( ispunct(text[i]) )
        {
            finaltext[i] = text[i];
        }
        if ( isupper(text[i]))
        {
            int index = 90 - text[i];
            if ( islower(key[25-index]) )
            {
                finaltext[i] = toupper(key[25-index]);
            }
            else
            {
                finaltext[i] = key[25-index];
            }
        }
        if ( islower(text[i]) )
        {
            int index = 122 - text[i];
            if ( isupper(key[25-index]) )
            {
                finaltext[i] = tolower(key[25-index]);
            }
            else
            {
                finaltext[i] = tolower(key[25-index]);
            }
        }

    }
    return finaltext;
}
