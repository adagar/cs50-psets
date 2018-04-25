// Copies a BMP file

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    //save the multiplier
    int multi = atoi(argv[1]);
    //verify multiplier is legitimate
    if (multi < 1 || multi > 100)
    {
        fprintf(stderr, "Multipler must be between 1-100\n");
        return 1;
    }
    //eprintf("Multipling image by: %i\n", multi);

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    //test to confirm new padding system is working
    // int oldPadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    // //eprintf("Old padding is: %i\n", oldPadding);

    //save original file variables
    int oldWidth = bi.biWidth;
    int oldHeight = bi.biHeight;
    int oldPadding = (4 - (oldWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //update the file header and/or info header to be the correct size
    bi.biWidth *= multi;
    bi.biHeight *= multi;

    //create array to write values to
    RGBTRIPLE pixelArray[bi.biWidth];

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    //eprintf("New padding is: %i\n", padding);

    //now that we've determined a new padding value, we can calculate a new size image
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + padding) * abs(bi.biHeight);
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);


    //now that new header values are calcuated, we can save to new file
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    //making sure width/height carrying over right
    //eprintf("New Width is: %i\n", bi.biWidth);
    //eprintf("New Height is: %i\n", bi.biHeight);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(oldHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < oldWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            //write each pixel multi-times
            for (int jMulti = 0; jMulti < multi; jMulti++)
            {
                // write RGB triple to outfile
                // fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);

                //using arithmetic to track counter without needing to update new variable
                int counter = (multi * j) + jMulti;
                //eprintf("counter: %i\n", counter); //verifying counter arithmetic checks out

                //write RGB triples to our pixel array
                pixelArray[counter] = triple;

            }
        }
        // skip over padding, if any
        fseek(inptr, oldPadding, SEEK_CUR);

        //now as many times as we're multiplying this image, we're going to write to height
        for(int iMulti = 0; iMulti < multi; iMulti++)
        {
            //eprintf("Writing line: %i number %i\n", i, iMulti);
            for(int arrayLooper = 0; arrayLooper < bi.biWidth; arrayLooper++)
            {
                //eprintf("Writing pixel: %i\n", arrayLooper);
                RGBTRIPLE thisPixel = pixelArray[arrayLooper];
                fwrite(&thisPixel, sizeof(RGBTRIPLE), 1, outptr);
            }

            // add padding it back (to demonstrate how)
            for (int k = 0; k < padding; k++)
            {
                fputc(0x00, outptr);
            }
        }

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
