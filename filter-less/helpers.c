#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int greyscale;
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            greyscale = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3.0);
            if (greyscale > 255)
            {
                greyscale = 255;
            }
            image[i][j].rgbtRed = greyscale;
            image[i][j].rgbtGreen = greyscale;
            image[i][j].rgbtBlue = greyscale;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i < height ; i++)
    {
        int sepiaRed;
        int sepiaGreen;
        int sepiaBlue;
        for (int j = 0 ; j < width ; j++)
        {
            // We apply the sepia algorithm
            sepiaRed = round( (0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue) );
            sepiaGreen = round( (0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue) );
            sepiaBlue = round( (0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue) );

            // We cap the max value for each sepia
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // We assign the new sepia values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // We create a buffer for the swap
    RGBTRIPLE first[height][width];

    for (int i = 0 ; i <  height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            first[i][j] = image[i][j];
        }
    }

    // We replace the pixels from right to left
    for (int i = 0; i < height ; i++)
    {
        for (int j = 0,k = width-1; j < width ; j++,k--)
        {
            image[i][j] = first[i][k];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // We create a buffer for the swap
    RGBTRIPLE first[height][width];
    // We create integers where we store the color values
    int totalred, totalgreen, totalblue;
    for (int i = 0 ; i <  height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            first[i][j] = image[i][j];
        }
    }

    //
    for (int i = 0; i < height ; i++)
    {
        for (int j = 0; j < width ; j++)
        {
            // If we are in top left corner
            if (i == 0 && j == 0)
            {
                totalred = round((first[i][j+1].rgbtRed + first[i+1][j].rgbtRed + first[i+1][j+1].rgbtRed)/3.0);
                totalgreen = round((first[i][j+1].rgbtGreen + first[i+1][j].rgbtGreen + first[i+1][j+1].rgbtGreen)/3.0);
                totalblue = round((first[i][j+1].rgbtBlue + first[i+1][j].rgbtBlue + first[i+1][j+1].rgbtBlue)/3.0);
                image[i][j].rgbtRed = totalred;
                image[i][j].rgbtGreen = totalgreen;
                image[i][j].rgbtBlue = totalblue;
            }
            // If we are in top right corner
            if (i == 0 && j == width-1)
            {
                totalred = round((first[i][j-1].rgbtRed + first[i+1][j].rgbtRed + first[i+1][j-1].rgbtRed)/3.0);
                totalgreen = round((first[i][j-1].rgbtGreen + first[i+1][j].rgbtGreen + first[i+1][j-1].rgbtGreen)/3.0);
                totalblue = round((first[i][j-1].rgbtBlue + first[i+1][j].rgbtBlue + first[i+1][j-1].rgbtBlue)/3.0);
                image[i][j].rgbtRed = totalred;
                image[i][j].rgbtGreen = totalgreen;
                image[i][j].rgbtBlue = totalblue;
            }
            // If we are in bottom left corner
            if (i == height-1 && j == 0)
            {
                totalred = round((first[i][j+1].rgbtRed + first[i-1][j].rgbtRed + first[i-1][j+1].rgbtRed)/3.0);
                totalgreen = round((first[i][j+1].rgbtGreen + first[i-1][j].rgbtGreen + first[i-1][j+1].rgbtGreen)/3.0);
                totalblue = round((first[i][j+1].rgbtBlue + first[i-1][j].rgbtBlue + first[i-1][j+1].rgbtBlue)/3.0);
                image[i][j].rgbtRed = totalred;
                image[i][j].rgbtGreen = totalgreen;
                image[i][j].rgbtBlue = totalblue;
            }
            // If we are in bottom right corner
            if ( i == height-1 && j == width-1)
            {
                totalred = round((first[i][j-1].rgbtRed + first[i-1][j].rgbtRed + first[i-1][j-1].rgbtRed)/3.0);
                totalgreen = round((first[i][j-1].rgbtGreen + first[i-1][j].rgbtGreen + first[i-1][j-1].rgbtGreen)/3.0);
                totalblue = round((first[i][j-1].rgbtBlue + first[i-1][j].rgbtBlue + first[i-1][j-1].rgbtBlue)/3.0);
                image[i][j].rgbtRed = totalred;
                image[i][j].rgbtGreen = totalgreen;
                image[i][j].rgbtBlue = totalblue;
            }
            // If we are in the first row
            if ( i == 0 && j != 0)
            {
                totalred = round((first[i][j+1].rgbtRed + first[i][j-1].rgbtRed + first[i+1][j-1].rgbtRed + first[i+1][j].rgbtRed + first[i+1][j+1].rgbtRed)/5.0);
                totalgreen = round((first[i][j+1].rgbtGreen + first[i][j-1].rgbtGreen + first[i+1][j-1].rgbtGreen + first[i+1][j].rgbtGreen + first[i+1][j+1].rgbtGreen)/5.0);
                totalblue = round((first[i][j+1].rgbtBlue + first[i][j-1].rgbtBlue + first[i+1][j-1].rgbtBlue + first[i+1][j].rgbtBlue + first[i+1][j+1].rgbtBlue)/5.0);
                image[i][j].rgbtRed = totalred;
                image[i][j].rgbtGreen = totalgreen;
                image[i][j].rgbtBlue = totalblue;
            }
            // If we are in the last row
            if ( i == height-1 && j != 0)
            {
                totalred = round((first[i][j-1].rgbtRed + first[i][j+1].rgbtRed + first[i-1][j-1].rgbtRed + first[i-1][j].rgbtRed + first[i-1][j+1].rgbtRed)/5.0);
                totalgreen = round((first[i][j-1].rgbtGreen + first[i][j+1].rgbtGreen + first[i-1][j-1].rgbtGreen + first[i-1][j].rgbtGreen + first[i-1][j+1].rgbtGreen)/5.0);
                totalblue = round((first[i][j-1].rgbtBlue + first[i][j+1].rgbtBlue + first[i-1][j-1].rgbtBlue + first[i-1][j].rgbtBlue + first[i-1][j+1].rgbtBlue)/5.0);
                image[i][j].rgbtRed = totalred;
                image[i][j].rgbtGreen = totalgreen;
                image[i][j].rgbtBlue = totalblue;
            }
            // If we are in the first column
            {
            if (i != 0 && j == 0)
            {
                totalred = round((first[i-1][j].rgbtRed + first[i-1][j+1].rgbtRed + first[i][j+1].rgbtRed + first[i+1][j].rgbtRed + first[i+1][j+1].rgbtRed)/5.0);
                totalgreen = round((first[i-1][j].rgbtGreen + first[i-1][j+1].rgbtGreen + first[i][j+1].rgbtGreen + first[i+1][j].rgbtGreen + first[i+1][j+1].rgbtGreen)/5.0);
                totalblue = round((first[i-1][j].rgbtBlue + first[i-1][j+1].rgbtBlue + first[i][j+1].rgbtBlue + first[i+1][j].rgbtBlue + first[i+1][j+1].rgbtBlue)/5.0);
                image[i][j].rgbtRed = totalred;
                image[i][j].rgbtGreen = totalgreen;
                image[i][j].rgbtBlue = totalblue;
            }
            }
            // If we are in the last column
            if (i != 0 && j == width-1)
            {
                totalred = round((first[i][j-1].rgbtRed + first[i-1][j].rgbtRed + first[i-1][j-1].rgbtRed + first[i+1][j].rgbtRed + first[i+1][j-1].rgbtRed)/5.0);
                totalgreen = round((first[i][j-1].rgbtGreen + first[i-1][j].rgbtGreen + first[i-1][j-1].rgbtGreen + first[i+1][j].rgbtGreen + first[i+1][j-1].rgbtGreen)/5.0);
                totalblue = round((first[i][j-1].rgbtBlue + first[i-1][j].rgbtBlue + first[i-1][j-1].rgbtBlue + first[i+1][j].rgbtBlue + first[i+1][j-1].rgbtBlue)/5.0);
                image[i][j].rgbtRed = totalred;
                image[i][j].rgbtGreen = totalgreen;
                image[i][j].rgbtBlue = totalblue;
            }
            else
            {
                totalred = round((first[i][j+1].rgbtRed + first[i][j-1].rgbtRed + first[i+1][j+1].rgbtRed + first[i+1][j].rgbtRed + first[i+1][j-1].rgbtRed + first[i-1][j+1].rgbtRed + first[i-1][j].rgbtRed + first[i-1][j-1].rgbtRed)/8.0);
                totalgreen = round((first[i][j+1].rgbtGreen + first[i][j-1].rgbtGreen + first[i+1][j+1].rgbtGreen + first[i+1][j].rgbtGreen + first[i+1][j-1].rgbtGreen + first[i-1][j+1].rgbtGreen + first[i-1][j].rgbtGreen + first[i-1][j-1].rgbtGreen)/8.0);
                totalblue = round((first[i][j+1].rgbtBlue + first[i][j-1].rgbtBlue + first[i+1][j+1].rgbtBlue + first[i+1][j].rgbtBlue + first[i+1][j-1].rgbtBlue + first[i-1][j+1].rgbtBlue + first[i-1][j].rgbtBlue + first[i-1][j-1].rgbtBlue)/8.0);
                image[i][j].rgbtRed = totalred;
                image[i][j].rgbtGreen = totalgreen;
                image[i][j].rgbtBlue = totalblue;
            }

        }
    }

    return;
}
