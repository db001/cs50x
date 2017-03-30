/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize enlarge_factor infile outfile\n");
        return 1;
    }

    // Get factor to enlarge by
    int n = atoi(argv[1]);

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
    
    // copy Bitmap headers for to then modify for outfile
    BITMAPFILEHEADER outBf = bf;
    BITMAPINFOHEADER outBi = bi;
    
    // Update values in Bitmap header by appropriate factors
    outBi.biWidth *= n;   // Width of image in pixels
    outBi.biHeight *= n;  // Height of image in pixels
    
    // calculate padding for new width
    int resPad = (4 - (outBi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    outBi.biSizeImage = ((outBi.biWidth * sizeof(RGBTRIPLE)) + resPad) * abs(outBi.biHeight);
    outBf.bfSize = outBi.biSizeImage + 14 + 40; // biSizeImage + header files (14 and 40 bytes)
    
    // Error checking information for resized bmp

    // fprintf(stderr, "bfType: %i %i\n", bf.bfType, outBf.bfType); 
    // fprintf(stderr, "bfSize: %i %i\n", bf.bfSize, outBf.bfSize); 
    // fprintf(stderr, "bfOffBits: %i %i\n", bf.bfOffBits, outBf.bfOffBits);
    // fprintf(stderr, "biSize: %i %i\n", bi.biSize, outBi.biSize); 
    // fprintf(stderr, "biWidth: %i %i\n", bi.biWidth, outBi.biWidth); 
    // fprintf(stderr, "biHeight: %i %i\n", bi.biHeight, outBi.biHeight); 
    // fprintf(stderr, "biBitCount: %i %i\n", bi.biBitCount, outBi.biBitCount); 
    // fprintf(stderr, "biSizeImage: %i %i\n", bi.biSizeImage, outBi.biSizeImage);
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&outBf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&outBi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // fprintf(stdout, "In padding: %i, Out Padding: %i\n", padding, resPad);
    
    // needed for fseek to prevent unsigned integer overflow when sending cursor back to beginning of line
    // see http://cs50.stackexchange.com/questions/22008/error-in-my-pset4-resize-c-code
    long offset = (bi.biWidth * sizeof(RGBTRIPLE)) + padding; 
    
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        
        // read scanline n times
        for (int x = 0; x < n; x++) {
        
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                        
                // temporary storage
                RGBTRIPLE triple;
                    
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                // write RGB triple to outfile n times
                for (int l = 0; l < n; l++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
                
            }
    
            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);
                        
            // add in new padding
            for (int k = 0; k < resPad; k++)
            {
                fputc(0x00, outptr);
            }
            
            if (x < n - 1) {
                fseek(inptr, -offset, SEEK_CUR);
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
