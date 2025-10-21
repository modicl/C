#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // We iterate every column
    for (int i= 0 ; i < width ; i++)
    {
        // We iterate every row
        for (int j = 0 ; j < height ; j++)
        {
            // We check if the pixel is black
            if (image[i][j].rgbtRed == 0 && image[i][j].rgbtGreen == 0 && image[i][j].rgbtBlue == 0)
            {
                // We replace for the color we wanted (orange in this case)
                image[i][j].rgbtRed = 255;
                image[i][j].rgbtGreen = 165;
                image[i][j].rgbtBlue = 0;

            }
        }
    }
}
