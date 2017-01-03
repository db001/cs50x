#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int height;
    do
    {
        printf("How high is your pyramid? ");
        height = get_int();
    } 
    while (23 < height || height < 0);
    
    
    printf("Height: %i\n", height);
}