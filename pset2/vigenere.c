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
    
    // Check for any numbers in the cipher
    for (int j = 0, x = strlen(argv[1]); j < x; j++) {
        if(isdigit(argv[1][j])) {
            printf("Invalid cipher");
            return 1;
        }
    }
    
    printf("plaintext: ");
    string text = get_string();
    
    if (text == NULL) {
        printf("String not usable\n");
        return 1;
    }
    
    
    
    string cipher = argv[1];
    int x = strlen(cipher);

    printf("ciphertext: ");
    
    int count = 0;
    
    for (int i = 0, n = strlen(text); i < n; i++) {
        
        if (isalpha(text[i])) {
            
            int c = text[i] + cipher[count % x];  // Needs to be an int to prevent overflow if c > 127
            
            if(isupper(text[i])) {
                c -= 65;
            } else if(islower(text[i])) {
                c -= 97;
                printf("%i", c);
            }
            
            if (islower(text[i]) && c > 122) {
                printf("%c\n", c - 26);
            } else if (isupper(text[i]) && c > 90) {
                printf("%c\n", c - 26);
            } else {
                printf("%c\n", c);
            }
            
            count += 1;
            
        } else {
            printf("%c", text[i]);
        }
         
    }
    
    printf("\n");
    
    return 0;
}