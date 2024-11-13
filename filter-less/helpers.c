#include "helpers.h"
#include <math.h>
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
            int pixelAverage = (redValue + greenValue + blueValue) / 3;
            // printf("Pixel average: %i - ", pixelAverage);

            // update pixel values
            image[i][j].rgbtRed = pixelAverage;
            image[i][j].rgbtGreen = pixelAverage;
            image[i][j].rgbtBlue = pixelAverage;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // loop through array[height]
    for (int i = 0; i < height; i++)
    {
        // loop through array[width]
        for(int j = 0; j < width; j++)
        {
            // get Sepia values
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaRed < 0)
            {
                sepiaRed = 0;
            }
            checkSepiaCap(sepiaRed);
            checkSepiaCap(sepiaGreen);
            checkSepiaCap(sepiaBlue);
            
            printf("Sepia R-G-B: %i-%i-%i | ", sepiaRed, sepiaGreen, sepiaBlue);

            // update pixel values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;

        }
    }
    return;
}

int checkSepiaCap (sepiaColor){
    if (sepiaColor > 255)
    {
        sepiaColor = 255;
    }
    if (sepiaColor < 0)
    {
        sepiaColor = 0;
    }
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
