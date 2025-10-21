#include <stdio.h>

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[7];

    // Create array to store plate numbers
    char *plates[8];

    FILE *infile = fopen(argv[1], "r");

    // We check if file is NULL
    if (infile == NULL)
    {
        printf("File not compatible/contains mistakes.\n");
        return 1;
    }

    // We declare an index for the iteration.
    int idx = 0;

    fread(buffer, 1, 7, infile);

    for (int i = 0 ; i < 6 ; i++)
    {
        printf("%c\n",buffer[i]);
    }
    fclose(infile);

}
