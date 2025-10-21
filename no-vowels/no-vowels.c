#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string replacetext(string word, int length);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("An argument (word) is required.\n");
        return 1;
    }
    else
    {
        for (int i = 1 ; i < argc ; i++)
        {
            string text = replacetext(argv[i], argc);
            printf("%s ",text);
        }
    }
}

string replacetext(string word, int length)
{
    for (int i = 0 ; i < strlen(word) ; i++)
    {
        switch (word[i])
        {
            case (65):
                word[i] = '4';
                break;

            case (97):
                word[i] = '4';
                break;

            case (69):
                word[i] = '3';
                break;

            case (101):
                word[i] = '3';
                break;

            case (73):
                word[i] = '1';
                break;

            case (105):
                word[i] = '1';
                break;

            case (79):
                word[i] = '0';
                break;

            case (111):
                word[i] = '0';
                break;

            case (85):
                word[i] = '5';
                break;

            case (117):
                word[i] = '5';
                break;

            default:
                word[i] = word[i];
                break;
        }
    }
    return word;
}