#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void) 
{
    
    long long cardNum;
    int doubles = 0;
    int otherDigits = 0;
    int total;
    int count = 0;
    bool validNum = false;
    
    // Example card num:
    // 378282246310005 (AmEx);
    // 4012888888881881 (VISA);
    // 5105105105105100 (MCard);
    
    // American Express numbers all start with 34 or 37 && are 15 digits long;
    // MasterCard numbers all start with 51, 52, 53, 54, or 55 && are 16 digits long;
    // Visa numbers all start with 4 && are 13 or 16 digits long;
    
    // Get card number and prompt if negative number is given
    do
    {
        printf("Number: ");
        cardNum = get_long_long();
    }
    while (cardNum <= 0);
    
    long long num = cardNum;

    // Go through card number and apply logic to individual digits
    while (num > 0)
    {
      if (count % 2 == 1) {
          int x = (num % 10) * 2;
          while (x > 0) {
              doubles += x % 10;
              x /= 10;
          }
          
      } else {
          otherDigits += num % 10;
      }
      num /= 10;
      count += 1;
    }
    
    // Check if last digit of total = 0 to show a valid card number
    total = doubles + otherDigits;
    
    if (total % 10 == 0) {
        validNum = true;
    }
    
    // Get first 2 digits of number
    int countMinus = count - 2;
    long long first = cardNum / (pow(10, countMinus));
    
    // Check if number length and first digits match
    if (validNum) {
        if (count == 15 && (first == 34 || first == 37)) {
            printf("AMEX\n");
        } else if (count == 16 && (first >= 51 && first <= 55)) {
            printf("MASTERCARD\n");
        } else if ((count == 13 || count == 16) && first / 10 == 4) {
            printf("VISA\n");
        } else {
            printf("INVALID\n");
        }
    } else {
        printf("INVALID\n");
    }
    
    // printf("Total: %i\nCount: %i\nValid Number: %s\n", total, count, validNum);
    // printf("First: %lld\n", first);
    
    return 0;
}