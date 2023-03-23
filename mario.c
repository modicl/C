#include <cs50.h>
#include <stdio.h>

int main(void)
{   // Asking for height (must be between 1 and 8 inclusive)
    int height;
    do

    height = get_int("Height of blocks: ");
    
    while(height <= 0 || height > 8);

    // Printing the blocks
    for (int i = 1; i <= height ; i++)
    {
        // To print spaces we check if k (height) is larger than i, if not, we stop (or we don't) printing blank spaces.
        // We start with "height" blank spaces and we substract for every iteration o i.
        for (int k = height; k > i; k--)
        {
            printf(" ");
        }
        // To print hashtags we check if j is lesser than i, when this is false we stop printing hashtags for the current row.
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        // At the end we always print a new line.
        printf("\n");
    }
}