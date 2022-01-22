#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "helper.h"
#include "sort.h"

// function prototypes
int sortAndSearchElementsStdLib();

int main(){
  printf("2.2 Sort and list - Library Function.\n");
  sortAndSearchElementsStdLib();

  return 0;
}

int sortAndSearchElementsStdLib(){
  int size = 400;
  Element *arr = initializeArrayOfElements(size);
  printArrayOfElements(arr, size);
  searchForInputStdLib(arr, 0, size);
  free(arr);
  return 0;
}
