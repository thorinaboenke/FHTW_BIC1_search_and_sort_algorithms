#include <stdio.h>

// helper function to print array with max 15 items per line
void printArray (float arr[], int length){
  for (int i = 0; i < length; i++){
    printf("%.3f ", arr[i]);
    if (i != 0 && (i+1) % 15 == 0){
      printf("\n");
    }
  }
  printf("\n");
}