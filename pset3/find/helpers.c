/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <math.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    
    /* Binary Search
    While list length > 0 -->
        Goto middle of list
        If number return true
        else if search item < middle --> search left
        else if search item > middle --> search right
    */
    
    int length = n;
    
    int start = 0;
    int finish = n;
    
    int middle;
    
    while (length > 0) {
        middle = floor((start + finish) / 2);
        if (value == values[middle]) {
            return true; 
        } else if (value < values[middle]) {
            finish = middle - 1;
        } else if (value > values[middle]) {
            start = middle + 1;
        }
        length = finish - start + 1;
    }
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    
    bool swapped = true;

    while (swapped) {
        swapped = false;
        for (int i = 0; i < n - 1; i++) {
            int one = values[i];
            int two = values[i + 1];
            if (one > two) {
                values[i] = two;
                values[i + 1] = one;
                swapped = true;
            }
        }
    }
    
    return;
}
