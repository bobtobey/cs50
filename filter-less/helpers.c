#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Function prototypes
int checkSepiaCap (int sepiaColor);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // buffer variable temp storage for reflection
    int16_t buffer;

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
            int pixelAverage = round((redValue + greenValue + blueValue) / 3.0);
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

            // Ensure Sepia values are between 0 to 255
            sepiaRed = checkSepiaCap(sepiaRed);
            sepiaGreen = checkSepiaCap(sepiaGreen);
            sepiaBlue = checkSepiaCap(sepiaBlue);

            // printf("Sepia R-G-B: %i-%i-%i | ", sepiaRed, sepiaGreen, sepiaBlue);

            // update pixel values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;

        }
    }
    return;
}
// Check Sepia values to be clamped at 0 to 255
int checkSepiaCap (int sepiaColor){
    if (sepiaColor > 255)
    {
        sepiaColor = 255;
    }
    if (sepiaColor < 0)
    {
        sepiaColor = 0;
    }
    return sepiaColor;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // loop through array[height]
    for (int i = 0; i < height; i++)
    {
        // loop through array[width]
        for(int j = 0; j < width; j++)
        {
            // Reflect pixel locations on horizontal opposite sides
            image[i][j] = image[i][(width - 1) - j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // loop through array[height]
    for (int i = 0; i < height; i++)
    {
        // loop through array[width]
        for(int j = 0; j < width; j++)
        {
            // Blur pixel values

        }
    }
    return;
}
