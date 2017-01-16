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
    
    printf("plaintext: ");
    string text = get_string();
    
    if (text == NULL) {
        printf("String not usable\n");
        return 2;
    }
    
    string cipher = argv[1];
    int x = strlen(cipher);
    
    printf("ciphertext: ");
    
    for (int i = 0, n = strlen(text); i < n; i++) {
        
        if (isalpha(text[i])) {
            char c = text[i] + cipher[i % x] - 97;
            if (c - 97 > 26) {
                printf("%c", c - 26);
            } else {
                printf("%c", c);
            }
        } else {
            printf("%c", text[i]);
        }
        
    }
    
    printf("\n");
    
    return 0;
}