#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (int argc, string argv[]) 
{
    // Check number of command line arguments
    if (argc != 2) {
        printf("Zero/too many command line argument(s)\n");
        return 1;
    }
    
    // Convert first argumenet to int and use remainder to get value < 26
    int shift = atoi(argv[1]) % 26;

    printf("plaintext: ");
    string text = get_string();
    
    if (text == NULL) {
        printf("String not usable\n");
        return 2;
    }
    
    for (int i = 0, n = strlen(text); i < n; i++) {
        // If char is 'A'-'Z'
        if (isupper(text[i]))
        {
            // If shift goes higher than 'Z' then wrap around
            if (text[i] + shift > 90) {
                text[i] += shift - 26;
            } else {
                text[i] += shift;
            }
            
        // If char is 'a'-'z'
        } else if (islower(text[i])) {
             if (text[i] + shift > 122) {
                // If shift goes higher than 'z' then wrap around
                text[i] += shift - 26;
            } else {
                text[i] += shift;
            }
        }
    }
    
    printf("ciphertext: %s\n", text);
    
    return 0;
}