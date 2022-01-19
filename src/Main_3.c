#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "helper.h"
#include "sort.h"

// function prototypes
void averageTime();

int main(){
  printf("1.3 Statistics for bubblesort performed 20 times on the same array of 2000 random numbers.\n");
  averageTime();
  return 0;
}

void averageTime(){
  int size = 2000;
  double times[20];
  int* input;
  for (int i= 0; i<20; i++){
    input = initializeArray(size);
    clock_t start_t, end_t, total_t;
    start_t = clock();
    bubbleSort(input, size);
    end_t = clock();
    total_t = (double)(end_t - start_t);
    times[i] = total_t;
    free(input);
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

  printf("Minimun runtime; %.0f microseconds\n", min );
  printf("Maximum runtime; %.0f microseconds\n", max );
  printf("Average runtime; %.0f microseconds\n", avg);
  printf("\n");
}
