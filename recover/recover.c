#include <stdio.h>
#include <stdlib.h>

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
    // TEMP storage for data read
    jpg_header[]
    // read bytes from input and load into temp header
    fread(header, HEADER_SIZE, 1, input);

    // search through data src for jpg string marker to mark start of file Start LOOP
        // In the LOOP you need to fread(data, sizie, number, inptr);
        // data is a pointer to where to store data your're reading (some buffer array)
        // size of each element to read
        // number of the elements to read
        // inptr FILE * to read from memory file in 512 byte chunks

    // continure till you find next jpg start string and then close that string and copy it over to new file IF STRING match execute COPY

    // then repeat process continue doing the same with the new file CONTINUE LOOP till end



}
