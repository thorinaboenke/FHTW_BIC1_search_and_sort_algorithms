#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "helper.h"
#include "sort.h"

// function prototypes

int comparePerformance();
void outputPerformance(char name[], int* array_of_inputs[], int sizes[], int length);


int main(){
  printf("1.2 Compare performance of sort algorithms on same data (arrays of different sizes)\n");
  comparePerformance();
  return 0;
}

int comparePerformance(){
  int sizes[] = {8,32,128, 512, 2048, 8192, 32768};
  int length = sizeof(sizes)/sizeof(sizes[0]);

  // array of pointers to int arrays
  // initialize arrays of different sizes
  int* input[7];
  for (int i = 0; i<length; i++){
    input[i] = initializeArray(sizes[i]);
  }

  int* copy_of_input[7];
  // allocate memory for the copies of the input
  for (int i = 0; i<length; i++){
    copy_of_input[i] = (int*)malloc(sizeof(int)*sizes[i]);
  }
  // copy over the values from original input array into copy
  for (int i = 0; i<length; i++){
    memcpy(copy_of_input[i], input[i], sizes[i]*sizeof(int));
  }

  outputPerformance(bub, copy_of_input, sizes,length);
  // reset input
  for (int i = 0; i<length; i++){
    memcpy(copy_of_input[i], input[i], sizes[i]*sizeof(int));
  }

  outputPerformance(ins, copy_of_input, sizes, length);
  // reset input
  for (int i = 0; i<length; i++){
    memcpy(copy_of_input[i], input[i], sizes[i]*sizeof(int));
  }

  outputPerformance(qui, copy_of_input, sizes, length);
  // reset input
  for (int i = 0; i<length; i++){
    memcpy(copy_of_input[i], input[i], sizes[i]*sizeof(int));
  }

  outputPerformance(mer, copy_of_input, sizes, length);
  // reset input
  for (int i = 0; i<length; i++){
    memcpy(copy_of_input[i], input[i], sizes[i]*sizeof(int));
  }

  // free memory
  for (int i = 0; i<length; i++){
    free(input[i]);
  }
  for (int i = 0; i<length; i++){
    free(copy_of_input[i]);
  }
  return 0;
}

void outputPerformance(char name[], int* array_of_inputs[], int sizes[], int length) {
  // TODO: make useable unit for ticks
  clock_t total_t, total_t_ascending, total_t_descending;
  printf("----------%s------------\n", name);
  // we measure performance in clock ticks. There are 1 million clock ticks per second on POSIX systems, that makes a microsecond per clock tick.
  printf("elements\tduration in us:\trandom\tascending\tdescending\n" );
  for (int i = 0; i<length; i++){
    // random input
    total_t = measureSort(name, array_of_inputs[i], sizes[i]);

    // input already sorted ascending
    total_t_ascending = measureSort(name, array_of_inputs[i], sizes[i]);

    // make input descending
    bubbleSortDescending(array_of_inputs[i], sizes[i]);

    // input already sorted descending
    total_t_descending = measureSort(name, array_of_inputs[i], sizes[i]);

    printf("%d\t\t\t\t%lu\t%lu\t\t%lu\n", sizes[i], total_t, total_t_ascending, total_t_descending);
  }
}
