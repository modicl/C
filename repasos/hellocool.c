#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);
    }
    if (argc == 3)
    {
        printf("hello, %s , de apellido %s jsjsjsj %s.\n",argv[1],argv[2],argv[0]);
    }
    else
    {
        printf("hello, world\n");
    }
}