#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "helper.h"

int main(){
  int sizes[3]={8,16, 64};
  int length = sizeof(sizes)/sizeof(sizes[0]);

  printf("----------Bubble Sort------------\n");
  for (int i=0; i<length; i++) {
  printf("Array with %d elements\n", sizes[i] );
  float * arr = initializeArray(sizes[i]);
  printArray(arr, sizes[i]);
  bubbleSort(arr,sizes[i]);
  printArray(arr, sizes[i]);
  checkAscending(arr, sizes[i]);
  printf(" \n");
  free(arr);
  }

  printf("----------Insertion Sort------------\n");
  for (int i=0; i<length; i++) {
  printf("Array with %d elements\n", sizes[i] );
  float * arr = initializeArray(sizes[i]);
  printArray(arr, sizes[i]);
  insertionSort(arr,sizes[i]);
  printArray(arr, sizes[i]);
  checkAscending(arr, sizes[i]);
  printf(" \n");
  free(arr);
  }

  printf("----------Merge Sort------------\n");
  for (int i=0; i<length; i++) {
  printf("Array with %d elements\n", sizes[i] );
  float * arr = initializeArray(sizes[i]);
  printArray(arr, sizes[i]);
  mergeSort(arr, 0, (sizes[i]-1));
  printArray(arr, sizes[i]);
  checkAscending(arr, sizes[i]);
  printf(" \n");
  free(arr);
  }

  printf("----------Quick Sort------------\n");
  for (int i=0; i<length; i++) {
  printf("Array with %d elements\n", sizes[i] );
  float * arr = initializeArray(sizes[i]);
  printArray(arr, sizes[i]);
  quickSort(arr, 0, (sizes[i]-1));
  printArray(arr, sizes[i]);
  checkAscending(arr, sizes[i]);
  printf(" \n");
  free(arr);
  }

  return 0;
}