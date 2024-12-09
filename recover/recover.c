#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Number of bytes in .jpg header
const int HEADER_SIZE = 512;

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
    // read bytes from input and load into temp header
    fread(jpg_header, HEADER_SIZE, 1, src);
    // check buffer data for beginning of JPEG string LOOP?
    while (fread(jpg_header, HEADER_SIZE, 1, src) == 1)
    {
        // Check for JPEG header
        printf("%s\n", jpg_header);
        if (jpg_header[0] == 0xff && jpg_header[1] == 0xd8 && jpg_header[2] == 0xff && (jpg_header[3] & 0xf0) == 0xe0)
        {
            // This is the start of a new JPEG
            // Create a JPEG file
        }
    }

    // search through data src for jpg string marker to mark start of file Start LOOP
        // IF then IF again
        // set counter to track jpgs found
        // copy it over to new file IF STRING match execute COPY
        // start copying at 000.jpg with sprintf(filename, "%03i.jpg", 2);
    // Open new JPEG file
        // then FILE *img = fopen(filename, "w");
    // Write 512 bytes until a new JPEG if found
        // use fwrite(data, size, number, outptr);

    // continure till you find next jpg start string and then close that string and copy it over to new file IF STRING match execute COPY

    // then repeat process continue doing the same with the new file CONTINUE LOOP till end
        // end of file look for end of file
    // stop at end of file




}
