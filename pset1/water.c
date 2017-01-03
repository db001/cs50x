#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int minutes;

    do
    {
        printf("How many minutes in the shower: ");
        minutes = get_int();
    }
    while (minutes < 0);
    
    int water = minutes * 12;
    
    printf("Minutes: %i\n", minutes);
    printf("Bottles: %i\n", water);
    
}
