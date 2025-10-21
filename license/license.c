#include <stdio.h>

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into and pass as array
    char buffer[7];

    // Create array to store plate numbers
    char plates[8][7];

    FILE *infile = fopen(argv[1], "r");

    // We check if file is NULL
    if (infile == NULL)
    {
        printf("File not compatible/contains mistakes.\n");
        return 1;
    }

    // We declare an index for the iteration.
    int idx = 0;

    while (fread(buffer, sizeof(char), 7, infile) == 7)
    {
        // Replace '\n' with '\0'
        buffer[6] = '\0';
        printf("%s\n",buffer);
        idx++;
    }

    fclose(infile);
}
