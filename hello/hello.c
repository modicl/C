#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Ask name
    string name = get_string("What's your name? ");
    // Print message
    printf("hello, %s\n",name);
}