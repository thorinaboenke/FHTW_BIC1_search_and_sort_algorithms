#include <stdio.h>

// helper function to swap array elements
void swap (float *a, float *b){
    float temp = *a;
    *a = *b;
    *b = temp;
  }