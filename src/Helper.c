#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// helper function to swap array elements
void swap (float *a, float *b){
    float temp = *a;
    *a = *b;
    *b = temp;
  }

//function to initialize array, allocate memory dynamically and return a float pointer to start address
float * initializeArray(int size) {

  srand((unsigned int) time(NULL));

  float *new_array = (float *)malloc(sizeof(float)*size);

  for(int i = 0; i < size; i++) {
  float random_number = (float)(rand() % 32767)/1000;
  // only 3 decimals

  if (rand() % 2 == 1) {
    random_number *= -1;
  }
  new_array[i] = random_number;
  }
  return new_array;
}

// helper function to check if array is sorted in ascending order
int checkAscending (float arr[], int length){
  for (int i = 0; i < length-1; i++){
    if ( arr[i] > arr[i+1]){
      printf("Array is not sorted\n");
      return 0;
    }
  }
  return 0;
}

void printArray (float arr[], int length){
  for (int i = 0; i < length; i++){
    printf("%.3f ", arr[i]);
    if ( i != 0 && (i+1) % 15 == 0){
      printf("\n");
    }
  }
  printf("\n");
}