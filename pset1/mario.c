#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (void)
{
    int height;
    do
    {
        printf("Height: ");
        height = get_int();
    } 
    while (23 < height || height < 0);
    
    if (height > 0)
    {
    
        for (int i = 1; i <= height; i++)
        {
        
            for (int x = height - i; x > 0; x--)
            {
                printf(" ");
            }
        
            for (int y = 1; y <= i; y++)
            {
                printf("#");
            }
            
            printf("  ");
            
            for (int z = 1; z <= i; z++)
            {
                printf("#");
            }
        
            printf("\n");
        
        }
    
    }
    
    return 0;
    
}