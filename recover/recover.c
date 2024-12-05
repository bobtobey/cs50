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
    // search through data src for jpg string marker to mark start of file Start LOOP

    // continure till you find next jpg start string and then close that string and copy it over to new file IF STRING match execute COPY

    // then repeat process continue doing the same with the new file CONTINUE LOOP till end



}
