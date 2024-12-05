#include <stdio.h>
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

    // Open camera data file
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

    // search through data src for jpg string marker to mark start of file Start LOOP
        // In the LOOP you need to fread(data, sizie, number, inptr);
        // data is a pointer to where to store data your're reading (some buffer array)
        // size of each element to read
        // number of the elements to read
        // inptr FILE * to read from memory file in 512 byte chunks

    // continure till you find next jpg start string and then close that string and copy it over to new file IF STRING match execute COPY

    // then repeat process continue doing the same with the new file CONTINUE LOOP till end



}
