#include <stdio.h>
#include <stdlib.h>

// dividing array into two partitions
int partition(float arr[], int low, int high){
  // last Element becomes pivot
  int pivot = arr[high];
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
  return i+1;
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