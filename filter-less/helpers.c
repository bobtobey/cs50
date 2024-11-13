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
            int sepia_red = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepia_green = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepia_blue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            // Ensure Sepia values are between 0 to 255
            sepia_red = checkSepiaCap(sepia_red);
            sepia_green = checkSepiaCap(sepia_green);
            sepia_blue = checkSepiaCap(sepia_blue);

            // printf("Sepia R-G-B: %i-%i-%i | ", sepia_red, sepia_green, sepia_blue);

            // update pixel values
            image[i][j].rgbtRed = sepia_red;
            image[i][j].rgbtGreen = sepia_green;
            image[i][j].rgbtBlue = sepia_blue;

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
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    // initialization
    int counter = 0;
    int ninj_red = 0;
    int ninj_green = 0;
    int ninj_blue = 0;

    // loop through array[height]
    for (int i = 0; i < height; i++)
    {
        // loop through array[width]
        for(int j = 0; j < width; j++)
        {
            // make a copy of image
            copy[i][j] = image[i][j];

            // Blur pixel values around sample average
            // targets the current, above, and below rows
            for (int di = -1; di <= 1; di++)
            {
                // targets the current, left, and right columns
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;
                    // Check if ni and nj are within bounds
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        // Access the pixel at (ni, nj)

                        ninj_sum_red += [ni][nj].rgbtRed;
                        ninj_sum_green += [ni][nj].rgbtGreen;
                        ninj_sum_blue += [ni][nj].rgbtBlue;
                        counter++;
                    }
                }
            }
            // get average of rgb
            ninj_avg_red = round(ninj_sum_red / counter);
            ninj_avg_green = round(ninj_sum_green / counter);
            ninj_avg_blue = round(ninj_sum_blue / counter);

            // int blur_pixel_value = (copy[i][j] + copy[i][j] + 1) * 2;

            // blur image pixel with average of colr
            // image[i][j] = blur_pixel_value;
        }
    }
    return;
}
