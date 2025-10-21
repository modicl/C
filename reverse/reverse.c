#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage of program : reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2

    FILE *inputwav = fopen(argv[1],"rb");
    if (inputwav == NULL)
    {
        printf("Could not open %s.\n",argv[1]);
        return 1;
    }

    // Read header
    // TODO #3
    WAVHEADER wf;
    fread(&wf,sizeof(WAVHEADER), 1, inputwav);

    // Use check_format to ensure WAV format
    // TODO #4
    if (check_format(wf) == 1)
    {
        printf("File is not WAV format\n.");
        return 1;
    }

    if(wf.audioFormat != 1)
    {
        return 1;
    }

    // Open output file for writing
    // TODO #5
    FILE *outputwav = fopen(argv[2],"wb");
    if (outputwav == NULL)
    {
        fclose(outputwav);
        printf("Could not create %s\n", argv[2]);
        return 1;
    }
    // Write header to file
    // TODO #6
    fwrite(&wf, sizeof(WAVHEADER), 1 ,outputwav);
    // Use get_block_size to calculate size of block
    // TODO #7
    int size = get_block_size(wf);
    // Write reversed audio to file
    // TODO #8
    if (fseek(inputwav,size,SEEK_END))
    {
        return 1;
    }
    BYTE buffer[size];
    while(ftell(inputwav) - size > sizeof(wf))
    {
        if(fseek(inputwav, -2*size,SEEK_CUR))
        {
            return 1;
        }
        fread(buffer,size,1,inputwav);
        fwrite(buffer,size,1,outputwav);
    }

    fclose(inputwav);
    fclose(outputwav);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
       return 0;
    }

    return 1;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    int size = header.numChannels * header.bitsPerSample / 8;
    return size;
}