#include <stdio.h>
#include <stdlib.h>
#include "helper.h"
#include "search.h"


// swap adjacent elements if they are in the wrong order
// after one interation the last element is correctly positioned, repeat again until second last element etc.
int bubbleSort(float arr[], int length){
   for (int i = 0; i<length-1; i++) {
     for (int j = 0; j < length-i-1; j++){
       if ( arr[j] > arr[j+1]){
         swap(&arr[j], &arr[j+1]);
       }
     }
   }
   return 0;
}


int insertionSort(float arr[], int length){
  for (int i = 0; i < length; i++) {
    float value_to_sort = arr[i];
    int j = i;
    // go backwards through the already sorted array to find the correct position
    // shift already sorted elements that are bigger to the right
    while (j > 0 && arr[j-1] > value_to_sort){
      arr[j] = arr [j-1];
      j--;
    }
    arr[j] = value_to_sort;
  }
return 0;
}

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

// dividing array into two partitions
int partition(float arr[], int low, int high){
  // last Element becomes pivot
  float pivot = arr[high];
  // i is temporary pivot index
  int i = (low - 1);

  for (int j = low; j < high; j++){
    if (arr[j] <= pivot){
       // move temporary pivot index forward
      i++;
      // swap current element with the element at the temporary pivot
      swap(&arr[i], &arr[j]);
    }
  }
  // move the pivot element to the correct pivot position (between smaller and larger elements)
  swap(&arr[i+1], &arr[high]);
  return (i+1);
}


// selecting a pivot element from the array and partitioning the other elements into two sub-arrays
// sort sub arrays recursively
int quickSort(float arr[], int low, int high){
  if (low < high) {
  // partition array and get pivot index
  int pivot = partition(arr, low, high);
  // Sort the two partitions
  quickSort(arr, low, pivot - 1); // sort left side of pivot
  quickSort(arr, pivot + 1, high); // sort right side of pivot
  }
  return 0;
}