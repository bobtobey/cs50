#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .jpg header
const int HEADER_SIZE = 512;
// jpeg correct match counter
int jpeg_match = 0;
// Declare filename for new jpg
char filename[8];

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: Please enter 1 argument.\n");
        return 1;
    }
    else
    {
        printf("Command line success\n");
    }

    // Open memory data file
    FILE *src = fopen(argv[1], "r");
    if (src == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    else
    {
        printf("Open Success.");
    }

    // TEMP buffer storage for data read
    uint8_t jpg_header[HEADER_SIZE];
    // Create variable for the new jpeg img file
    FILE *img = NULL;
    // Read bytes from input and load into temp header, while looping through data chunks
    while (fread(jpg_header, HEADER_SIZE, 1, src) == 1)
    {
        // Check for JPEG header for beginning of JPEG string
        if (jpg_header[0] == 0xff && jpg_header[1] == 0xd8 && jpg_header[2] == 0xff && (jpg_header[3] & 0xf0) == 0xe0)
        {
            // Check if there's an image file already open writing data
            if (img != NULL)
            {
                fclose(img);
            }
            // Create a new JPEG file to write data to
            sprintf(filename, "%03i.jpg", jpeg_match);
            // This is the start of a new JPEG - count matches
            jpeg_match++;
            // Open the new file
            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("Could not open file.\n");
                fclose(src);
                return 1;
            }
        }
        // Check if new image file is still open
        if (img != NULL)
        {
            fwrite(jpg_header, HEADER_SIZE, 1, img);
        }
    }
    // Close last image if open
    if (img != NULL)
    {
        fclose(img);
    }
    // Close src file
    fclose(src);

    // printf("Total JPEG headers found: %d\n", jpeg_match);
}
