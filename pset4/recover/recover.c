#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover file.raw\n");
        return 1;
    }
    
    char *infile = argv[1];
    
    FILE *raw = fopen(infile, "r");
    
    if (raw == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    
    fclose(raw);
}