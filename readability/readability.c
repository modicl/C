#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

int lcount(string text);
int wcount(string text);
int sencount(string text);

int main(void)
{
    string text = get_string("Please insert text you wish to analyse: ");
    int lettercount = lcount(text);
    int wordcount = wcount(text);
    int sentcount = sencount(text);
    double index = (0.0588 * (double) lettercount/ (double) wordcount*100) - (0.296 * (double) sentcount/(double) wordcount*100) - 15.8;

    // If index is lower than 1 we print "before grade 1"
    if (index < 1)
    {
        printf("Before Grade 1...");
    }

    // If index is greater than 16 we just print "grade 16+"
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf(" Grade %.0f\n", round(index));
    }

}


int lcount(string text)
{
    // Function that counts how many letters we have in a text
    // We count everything that is a letter
    int lettercount = 0;
    for (int i = 0 ; i < strlen(text) ; i++)
    {
        if ( isalpha(text[i]) )
        {
            lettercount++;
        }
    }
    return lettercount;
}

int wcount(string text)
{
    // We will count depending if the character is a space and the next is not a space.
    // Or if it as new line of text or a tabulation.
    // Or, we will count if it is a word if the next index in the array is a nul character.
    int wordcount = 0;
    for (int i = 0 ; i < strlen(text) ; i++)
    {
        if( (text[i]==' ' && text[i+1] != ' ') || text[i]=='\n' || text[i]=='\t' || text[i+1] == '\0')
        {
            wordcount++;
        }

    }
    return wordcount;
}

int sencount(string text)
{
    // We will count something as a sentence if it ends in : '?' , '.' or '!'
    int sentcount = 0;
    for (int i = 0; i < strlen(text) ; i++)
    {
        if ( text[i] == '?' || text[i] == '!' || text[i] == '.')
        {
            sentcount ++;
        }
    }
    return sentcount;
}