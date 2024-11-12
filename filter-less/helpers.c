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
            int sepiaRed = .393 * image[i][j].rgbtRed + .769 * originalGreen + .189 * originalBlue;

            // update pixel values

        }
    }
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
