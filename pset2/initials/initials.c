#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = get_string();
    if (s != NULL)
    {
        if (s[0] != 32) {
            printf("%c", toupper(s[0]));
        }
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            if (i < n - 1 && s[i] == 32 && s[i + 1] != 32) {
                printf("%c", toupper(s[i + 1]));
            }
            
        }
        printf("\n");
        return 0;
        
    } else {
        return 1;
    }
    
}