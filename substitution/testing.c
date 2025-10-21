#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

string cipherme(string key, string text);

int main(void)
{
    string key = get_string("Give me your key:\n");
    string text = get_string("Text to cipher:");
    printf("Final : %s\n",cipherme(key,text));
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