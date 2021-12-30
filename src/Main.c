#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "sort.h"
#include "helper.h"

// function prototypes
int outputSorts();
void outputSort(char name[], int sizes[], int length, int (*sort_function)(float[], int));
void outputSort2(char name[], int sizes[], int length, int (*sort_function)(float[], int, int));
int comparePerformance();
void outputPerformance(char name[], float* array_of_inputs[], int sizes[], int length, int (*sort_function)(float[], int));
void outputPerformance2(char name[], float* array_of_inputs[], int sizes[], int length, int (*sort_function)(float[], int, int));
void averageTime();


// global variables
char bub[] = "Bubblesort";
char ins[] = "Insertionsort";
char mer[] = "Mergesort";
char qui[] = "Quicksort";

int main(){
  printf("1.1 Implement sort algorithms\n");
  outputSorts();
  printf("1.2 Compare performance of sort algorithms on same data (arrays of different sizes)\n");
  comparePerformance();
  printf("1.3 Statistics for bubblesort performed 20 times on the same array of 2000 random numbers.\n");
  averageTime();
  return 0;
}

int outputSorts(){
  int sizes[3]= {8,16,64};
  int length = sizeof(sizes)/sizeof(sizes[0]);
  outputSort(bub, sizes, length, bubbleSort);
  outputSort(ins, sizes, length, insertionSort);
  outputSort2(mer, sizes, length, mergeSort);
  outputSort2(qui, sizes, length, quickSort);
  return 0;
}

// for sort function that take array and array length as parameters
void outputSort(char name[], int sizes[], int length,  int (*sort_function)(float[], int)){
  printf("----------%s------------\n", name);
  for (int i=0; i<length; i++) {
    printf("Array with %d elements\n", sizes[i] );
    float * arr = initializeArray(sizes[i]);
    printArray(arr, sizes[i]);
    sort_function(arr,sizes[i]);
    printArray(arr, sizes[i]);
    checkAscending(arr, sizes[i]);
    printf(" \n");
    free(arr);
  }
}

// for sort function that take array, start index and end index as parameter
void outputSort2(char name[], int sizes[], int length,  int (*sort_function)(float[], int, int)){
  printf("----------%s------------\n", name);
  for (int i=0; i<length; i++) {
    printf("Array with %d elements\n", sizes[i] );
    float * arr = initializeArray(sizes[i]);
    printArray(arr, sizes[i]);
    sort_function(arr, 0, (sizes[i]-1));
    printArray(arr, sizes[i]);
    checkAscending(arr, sizes[i]);
    printf(" \n");
    free(arr);
  }
}

int comparePerformance(){
  int sizes[] = {8,32,128, 512, 2048, 8192, 32768};
  int length = sizeof(sizes)/sizeof(sizes[0]);

  // array of pointers to float arrays
  // initialize arrays of different sizes
  float* input[7];
  for (int i = 0; i<length; i++){
    input[i] = initializeArray(sizes[i]);
  }

  float* copy_of_input[7];
  // allocate memory for the copies of the input
  for (int i = 0; i<length; i++){
    copy_of_input[i] = (float*)malloc(sizeof(float)*sizes[i]);
  }
  // copy over the values from original input array into copy
  for (int i = 0; i<length; i++){
    memcpy(copy_of_input[i], input[i], sizes[i]*sizeof(float));
  }

  outputPerformance(bub, copy_of_input, sizes,length, bubbleSort);
  // reset input
  for (int i = 0; i<length; i++){
    memcpy(copy_of_input[i], input[i], sizes[i]*sizeof(float));
  }

  outputPerformance(ins, copy_of_input, sizes, length, insertionSort);
  // reset input
  for (int i = 0; i<length; i++){
    memcpy(copy_of_input[i], input[i], sizes[i]*sizeof(float));
  }

  outputPerformance2(qui, copy_of_input, sizes, length, quickSort);
  // reset input
  for (int i = 0; i<length; i++){
    memcpy(copy_of_input[i], input[i], sizes[i]*sizeof(float));
  }

  outputPerformance2(mer, copy_of_input, sizes, length, mergeSort);
  // reset input
  for (int i = 0; i<length; i++){
    memcpy(copy_of_input[i], input[i], sizes[i]*sizeof(float));
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

// for sort function that take array and array length as parameters
void outputPerformance(char name[], float* array_of_inputs[], int sizes[], int length,  int (*sort_function)(float[], int)){
  clock_t start_t, end_t, total_t, start_t_ascending, end_t_ascending, total_t_ascending, start_t_descending, end_t_descending, total_t_descending;
  printf("----------%s------------\n", name);
  printf("elements\tduration:\trandom\tascending\tdescending\n" );
  for (int i = 0; i<length; i++){
  start_t = clock();
  sort_function(array_of_inputs[i],sizes[i]);
  end_t = clock();
  total_t = (double)(end_t - start_t);

  // time if already ascending sorted array
  start_t_ascending = clock();
  sort_function(array_of_inputs[i],sizes[i]);
  end_t_ascending = clock();
  total_t_ascending = (double)(end_t_ascending - start_t_ascending);

  bubbleSortDescending(array_of_inputs[i], sizes[i]);

   // time if already descending sorted array
  start_t_descending = clock();
  sort_function(array_of_inputs[i],sizes[i]);
  end_t_descending = clock();
  total_t_descending = (double)(end_t_descending - start_t_descending);

  printf("%d\t\t\t\t%lu\t%lu\t\t%lu\n", sizes[i], total_t, total_t_ascending, total_t_descending);
  }
}

// for sort function that take array, start index and end index as parameter
void outputPerformance2(char name[], float* array_of_inputs[], int sizes[], int length, int (*sort_function)(float[], int, int)){
  clock_t start_t, end_t, total_t, start_t_ascending, end_t_ascending, total_t_ascending, start_t_descending, end_t_descending, total_t_descending;
  printf("----------%s------------\n", name);
  printf("elements\tduration:\trandom\tascending\tdescending\n" );
  for (int i = 0; i<length; i++){
  start_t = clock();
  sort_function(array_of_inputs[i],0,sizes[i]-1);
  end_t = clock();
  total_t = (double)(end_t - start_t);

  // time if already ascending sorted array
  start_t_ascending = clock();
  sort_function(array_of_inputs[i],0,sizes[i]-1);
  end_t_ascending = clock();
  total_t_ascending = (double)(end_t_ascending - start_t_ascending);

  bubbleSortDescending(array_of_inputs[i], sizes[i]);

   // time if already descending sorted array
  start_t_descending = clock();
  sort_function(array_of_inputs[i],0,sizes[i]-1);
  end_t_descending = clock();
  total_t_descending = (double)(end_t_descending - start_t_descending);

  printf("%d\t\t\t\t%lu\t%lu\t\t%lu\n", sizes[i], total_t, total_t_ascending, total_t_descending);
  }
}

void averageTime(){
  int size = 2000;
  double times[20];
  float* input = initializeArray(size);
  float* copy_of_input = initializeArray(size);
  for (int i= 0; i<20; i++){
    memcpy(copy_of_input, input, size*sizeof(float));
    clock_t start_t, end_t, total_t;
    start_t = clock();
    bubbleSort(copy_of_input, size);
    end_t = clock();
    total_t = (double)(end_t - start_t);
    times[i] = total_t;
  }
  double sum, avg, min, max;
  min = times[0];
  max = times[0];
  sum = 0;
  for (int j = 0; j<20; j++){
    if (times[j] < min){
      min = times[j];
    }
    if (times[j] > max){
      max = times[j];
    }
    sum += times[j];
  }
  avg = sum/20;
  free(input);
  free(copy_of_input);

  printf("Minimun runtime; %.0f\n", min );
  printf("Maximum runtime; %.0f\n", max );
  printf("Average runtime; %.0f\n", avg);
  printf("\n");
}
