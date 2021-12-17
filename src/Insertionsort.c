#include <stdio.h>
#include <stdlib.h>

int insertionSort(float arr[], int length){
  for (int i = 0; i < length; i++) {
    float value_to_sort = arr[i];
    int j = i;
    // go backwards through the already sorted array to find the correct position
    // shift already sorted elements that are bigger to the right
    while (j > 0 && arr[j-1] > value_to_sort){
      arr[j] = arr [j-1];
      j--;
    }
    arr[j] = value_to_sort;
  }
return 0;
}