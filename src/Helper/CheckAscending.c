#include <stdio.h>
#include <stdlib.h>

// helper function to check if array is sorted in ascending order
int checkAscending (float arr[], int length){
  for (int i = 0; i < length-1; i++){
    if ( arr[i] > arr[i+1]){
      printf("Array is not sorted\n");
      return 0;
    }
  }
  printf("Array is sorted\n");
  return 0;
}