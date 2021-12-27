#include <stdio.h>
#include <stdlib.h>

// merges two already sorted subarrays into one array
int merge(float arr[], int low, int middle, int high){

  int a1 = middle - low + 1;
  int a2 = high - middle;

  // temporary arrays
  float L[a1], R[a2];

  // copies data to temporary arrays
  for (int i = 0; i < a1; i++){
    L[i] = arr[low+i];
  }
  for (int j = 0; j < a1; j++){
    R[j] = arr[middle + 1 +j];
  }

  // This maintains current index of sub-arrays and main array
  int i = 0; // Initial index of first subarray L
  int j = 0; // Initial index of second subarray R
  int k = low; // Initial index of merged subarray

  // Until the end of either subarray, pick larger among the elements and place in correct position in arr
  while(i < a1 && j < a2){
    if (L[i] <= R[j]){
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  // When running out of Elements in either L or R, remaining elements in the other are put in arr
  while(i < a1){
    arr[k] = L[i];
    i++;
    k++;
  }
  while(j < a2){
    arr[k] = R[j];
    j++;
    k++;
  }
  return 0;
}

int mergeSort(float arr[], int low, int high){
  if (low >= high){
    return 0;
  }
  int middle = (low+high) / 2;
  // recursively mergeSort halves of the array
  mergeSort(arr, low, middle);
  mergeSort(arr, middle+1, high);
  merge(arr, low, middle, high);
return 0;
}
