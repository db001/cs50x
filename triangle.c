#include <stdio.h>
#include <cs50.h>

bool valid_triangle(int a, int b, int c);

int main(void)
{
    bool x = valid_triangle(-2, 5, 4);
    printf("%s\n", x ? "True" : "False");
}

bool valid_triangle(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0) {
        printf("Input less than 0\n");
        return false;
    }
    else if (a + b < c || a + c < b || b + c < a) {
        printf("Sum less than other side\n");
        return false;
    } else {
        return true;
    }
}