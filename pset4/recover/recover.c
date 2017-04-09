#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[]) 
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover filename\n");
        return 1;
    }
    
    char *infile = argv[1];
    
    FILE *rawFile = fopen(infile, "r");
    
    // Check to see if input file can be opened
    if (rawFile == NULL)
    {
        fprintf(stderr, "Could not open raw file.\n");
        return 2;
    }
    
    // Create buffer to store 512 byte blocks
    BYTE buffer[512];
    
    FILE *outptr = NULL;
    
    // Initiate counter to keep track of picture numbers
    int picNum = 0;
    
    // array to create file names
    char fileName[8];
    
    // While the buffer is reading full blocks of 512 bytes
    while(fread(&buffer, 512, 1, rawFile) == 1) 
    {
        // check to see if it's the start of a jpeg
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
            {
               
                // if file is open: close it
                if (outptr != NULL) 
                {
                    fclose(outptr);
                }
                
                // Create file name and open file
                sprintf(fileName, "%03d.jpg", picNum);
                outptr = fopen(fileName, "w");
                
                // Write buffer to open file
                fwrite(&buffer, sizeof(buffer), 1, outptr);
                
                // Increment picture number
                picNum++;
           }
           
        // If jpg signature not found but file is open
        else
        {
            if(outptr != NULL)
            {
                // write buffer to file
                fwrite(&buffer, sizeof(buffer), 1, outptr);
            }
        }

    }
    
    fclose(rawFile);
    
    return 0; // All is well
}