#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "helper.h"
#include "sort.h"

// function prototypes
int sortAndSearchElements();

int main(){
  printf("2.1 Sort and list - self-implemented.\n");
  sortAndSearchElements();
  return 0;
}

int sortAndSearchElements() {
  int size = 400;
  Element *arr = initializeArrayOfElements(size);
  printArrayOfElements(arr, size);
  searchForInput(arr, 0, size);
  free(arr);
  return 0;
}
