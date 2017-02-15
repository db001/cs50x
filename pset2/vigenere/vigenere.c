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
    
    // Loop through input text
    for (int i = 0, len = strlen(text); i < len; i++) {
        
        int shift;
        
        // Check that char is a letter
        if(isalpha(text[i])) {
            
            // Check is the cipher is upper or lowercase and set shift accordingly
            if(isupper(cipher[count % x])) {
                shift = cipher[count % x] - 65;
            } else {
                shift = cipher[count % x] - 97;
            }
            
            if (isupper(text[i])) {
                // If shift + text[i] goes higher than 'Z' then wrap around
                if (text[i] + shift > 90) {
                    text[i] += shift - 26;
                } else {
                    text[i] += shift;
                }
            
            } else if (islower(text[i])) {
                // If shift + text[i] goes higher than 'z' then wrap around
                if (text[i] + shift > 122) {
                    text[i] += shift - 26;
                } else {
                    text[i] += shift;
                }
            }
            
            printf("%c", text[i]);
            count++;
            
        } else {
            // Print char without shift if not a letter
            printf("%c", text[i]);
        }
        
    }
    
    printf("\n");
    
    return 0;
}