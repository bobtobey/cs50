#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Function prototypes
int checkSepiaCap (int sepia_color);

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
            int red_value = image[i][j].rgbtRed;
            int green_value = image[i][j].rgbtGreen;
            int blue_value = image[i][j].rgbtBlue;
            int pixel_average = round((red_value + green_value + blue_value) / 3.0);
            // printf("Pixel average: %i - ", pixel_average);

            // update pixel values
            image[i][j].rgbtRed = pixel_average;
            image[i][j].rgbtGreen = pixel_average;
            image[i][j].rgbtBlue = pixel_average;

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
int checkSepiaCap (int sepia_color){
    if (sepia_color > 255)
    {
        sepia_color = 255;
    }
    if (sepia_color < 0)
    {
        sepia_color = 0;
    }
    return sepia_color;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // buffer variable temp storage for reflection
    RGBTRIPLE buffer;
    RGBTRIPLE buffer_reflection;

    // loop through array[height]
    for (int i = 0; i < height; i++)
    {
        // loop through array[width]
        for(int j = 0; j < width / 2; j++)
        {
            // Reflect pixel locations on horizontal opposite sides
            buffer = image[i][(width - 1) - j];
            buffer_reflection = image[i][j];
            image[i][j] = buffer;
            image[i][(width - 1) - j] = buffer_reflection;
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
