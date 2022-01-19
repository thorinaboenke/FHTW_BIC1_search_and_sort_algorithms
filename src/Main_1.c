#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "helper.h"
#include "sort.h"

// function prototypes
int outputSorts();
int outputSort(char name[], int sizes[], int length);

int main(){
  printf("1.1 Implement sort algorithms\n");
  outputSorts();
  return 0;
}

int outputSorts(){
  int sizes[3]= {8,16,64};
  int length = sizeof(sizes)/sizeof(sizes[0]);
  outputSort(bub, sizes, length);
  outputSort(ins, sizes, length);
  outputSort(mer, sizes, length);
  outputSort(qui, sizes, length);
  return 0;
}

// for sort function that take array and array length as parameters
int outputSort(char name[], int sizes[], int length) {
  printf("----------%s------------\n", name);
  for (int i=0; i<length; i++) {
    printf("Array with %d elements\n", sizes[i]);
    int * arr = initializeArray(sizes[i]);
    printArray(arr, sizes[i]);
    executeSort(name, arr, sizes[i]);
    printArray(arr, sizes[i]);
    checkAscending(arr, sizes[i]);
    printf(" \n");
    free(arr);
  }
  return 0;
}
