//goes through raw to find missing images
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#include <stdint.h>

//Replacing header file with in-line definitions since it otherwise fails check50
typedef uint8_t  BYTE;

typedef struct
{
    BYTE part1;
    BYTE part2;
    BYTE part3;
    BYTE part4;
} __attribute__((__packed__))
JPEGHEADER;
//END header file


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: recovery rawfile\n");
        return 1;
    }

    //open memory card file with fopen
    //save filename
    char *rawFile = argv[1];

    // open input file
    FILE *inptr = fopen(rawFile, "r");

    //delcare an output file
    FILE *outptr;
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", rawFile);
        return 2;
    }

    //set aside 512bytes to store memory chunks
    BYTE buffer[512];
    //save what an appropriate header for a jpeg looks like
    JPEGHEADER jpegHeader =
    {
        0xff,
        0xd8,
        0xff,
        0xe0
    };

    //track whether a file is already written to
    bool jpegOpen = false;

    //for tracking filename
    char fileName[50];
    int jpegCounter = 0;

    do
    {
        //eprintf("Byte: 0x%02X\n", buffer[0]);

        //read 512b into card
        fwrite(&buffer, 512, 1, inptr);


        //check if the start of block is a JPEG header
        if (buffer[0] == jpegHeader.part1
        && buffer[1] == jpegHeader.part2
        && buffer[2] == jpegHeader.part3)
        {
            //is a JPEG already open?
            if (jpegOpen)
            {
                //close previous JPG
                fclose(outptr);
                jpegOpen = false;
            }

            //start new JPG
            sprintf(fileName, "%03i.jpg", jpegCounter);
            // open output file
            outptr = fopen(fileName, "w");
            jpegOpen = true;

            eprintf("%s FOUND!\n", fileName);
            jpegCounter++;

            fwrite(&buffer, 512, 1, outptr);
        }

        //if it isn't
        else
        {
            //is a JPEG already open?
            if (jpegOpen)
            {
                fwrite(&buffer, 512, 1, outptr);
            }
            else
            {
                //check next block
                continue;
            }

        }





    }
    while (fread(buffer, 1, 512, inptr) == 512);

    fclose(outptr);

    return 0;
}