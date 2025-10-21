#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("Cual es el nombre de la persona? ");
    string number = get_string("Cual es el numero de la persona? ");
    string address = get_string("Cual es la direccion de la persona? ");

    printf("Estan bien estos datos?:\n");
    printf("******************************\n");
    printf("Nombre : %s\n",name);
    printf("Numero : %s\n", number);
    printf("Direccion : %s\n",address);
}