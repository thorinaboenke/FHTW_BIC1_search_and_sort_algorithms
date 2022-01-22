#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


//function to initialize array, allocate memory dynamically and return a float pointer to start address
float * initializeArray(int size) {

  srand((unsigned int) time(NULL));

  float *new_array = (float *)malloc(sizeof(float)*size);

  for(int i = 0; i < size; i++) {
  float random_number = (float)(rand() % 32767)/1000;
  // only 3 decimals

  // make every 2nd number negative
  if (rand() % 2 == 1) {
    random_number *= -1;
  }
  new_array[i] = random_number;
  }
  return new_array;
}
