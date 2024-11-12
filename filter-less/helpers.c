#include "helpers.h"
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // loop through array[height]
    for (int i = 0; i < height; i++)
    {
        // loop through array[width]
        for(int j = 0; j < width; j++)
        {
            // get average of rgb
            int redValue = image[i][j].rgbtRed;
            int greenValue = image[i][j].rgbtGreen;
            int blueValue = image[i][j].rgbtBlue;
            int pixelAverage = (redValue + greenValue + blueValue) / 3.0;
            printf("Pixel average: %i - ", pixelAverage);

            // update pixel values
            FILE *src = fopen(argv[1], "rb");
            FILE *dst = fopen(argv[2], "rb");
            BYTE buffer;

            while (fread(&buffer, sizeof(buffer), 1, src) != 0)
            {
                // write pixel change
                fwrite(&buffer, sizeof(buffer), 1, dst);
            }

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
