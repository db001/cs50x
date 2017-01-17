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
    
    int count = 0;
    
    for (int i = 0, n = strlen(text); i < n; i++) {
        
        int c = text[i] + cipher[count % x] - 97; // Needs to be an int as char overflows at more than 127
        
        if (isalpha(text[i])) {
            
            if (islower(text[i]) && c > 122) {
                printf("%c", c - 26);
            } else if (isupper(text[i]) && c > 90) {
                printf("%c", c - 26);
            } else {
                printf("%c", c);
            }
            
            count += 1;
            
        } else {
            printf("%c", text[i]);
        }
         
    }
    
    printf("\n");
    
    return 0;
}