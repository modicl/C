#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string a = get_string("Cual es tu nombre? ");
    printf("Hola %s, bienvenido!\n", a);
}