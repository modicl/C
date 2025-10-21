#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // We get the index of the score by substracting the last ascii value of upper or lower alphabet
    int finalscore = 0;
    for (int i = 0 ; i < strlen(word) ; i++)
    {
    // If the character is upper we start from the value of 90 and susbtract the value of the letter for indexing
        if ( (isupper(word[i])) )
        {
            int index = 90 - (word[i]);
            finalscore += POINTS[24-index+1];
        }
    // If the character is lower we start from the value of 122 and susbtract the value of the letter for indexing
        if ( (islower(word[i])) )
        {
            int index = 122 - (word[i]);
            finalscore += POINTS[24-index+1];
        }
    // We ignore any symbol or punctuation char
        if ( ispunct(word[i]) )
        {
            finalscore += 0;
        }
    }
    return finalscore;
}
