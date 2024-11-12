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
            int greenValue = image[i][j].rgbtgreen;
            int blueValue = image[i][j].rgbtblue;
            pixelAverage = (redValue + greenValue + blueValue);
            // printf("Red value: %i - ", redValue);
            printf("Pixel average: %i ", pixelAverage);
            // update pixel values
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
