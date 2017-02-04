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
        
        // Convert char at i'th index of cipher to an int and use remainder to get value 0 < shift <= 26
        int shift = cipher[count % x];
        
        if(isalpha(text[i])) {
        
            // If char is uppercase...
            if (isupper(text[i]))
            {
                shift -= 65;
                printf("Text[i]: %c %i, Shift: %i ", text[i], text[i], shift);
                // If shift goes higher than 'Z' then wrap around
                if (text[i] + shift > 90) {
                    printf("%c\n", text[i] += shift - 26);
                } else {
                    printf("%c\n", text[i] += shift);
                }
                
            // If char is lowercase...
            } else if (islower(text[i])) {
                shift -= 97;
                printf("Text[i]: %c %i, Shift: %i ", text[i], text[i], shift);
                // If shift goes higher than 'z' then wrap around
                if (text[i] + shift > 122) {
                    printf("%c\n", text[i] += shift - 26);
                } else {
                    printf("%c\n", text[i] += shift);
                }
            }
            count += 1;
        } else {
            printf("Text[i]: %c %i, Shift: %i ", text[i], text[i], shift);
            printf("%c\n", text[i]);
        }
    }
    
    printf("\n");
    
    return 0;
}