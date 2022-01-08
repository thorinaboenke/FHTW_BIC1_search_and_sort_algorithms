#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "helper.h"
#include "search.h"

// TODO: make charset length a global variable and use everywhere

// global variables
char bub[] = "Bubblesort";
char ins[] = "Insertionsort";
char mer[] = "Mergesort";
char qui[] = "Quicksort";


// BUBBLE SORT

// swap adjacent elements if they are in the wrong order
// after one interation the last element is correctly positioned, repeat again until second last element etc.
int bubbleSort(int arr[], int length){
   for (int i = 0; i<length-1; i++) {
     for (int j = 0; j < length-i-1; j++){
       if ( arr[j] > arr[j+1]){
         swap(&arr[j], &arr[j+1]);
       }
     }
   }
   return 0;
}

int bubbleSortDescending(int arr[], int length){
   for (int i = 0; i<length-1; i++) {
     for (int j = 0; j < length-i-1; j++){
       if ( arr[j] < arr[j+1]){
         swap(&arr[j], &arr[j+1]);
       }
     }
   }
   return 0;
}

// INSERTION SORT

int insertionSort(int arr[], int length){
  for (int i = 0; i < length; i++) {
    int value_to_sort = arr[i];
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

// MERGE SORT

// merges two already sorted subarrays into one array
int merge(int arr[], int low, int middle, int high){

  int a1 = middle - low + 1;
  int a2 = high - middle;

  // temporary arrays
  int L[a1], R[a2];

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

int mergeSort(int arr[], int low, int high){
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

// QUICK SORT OF INT ARRAY

// dividing array into two partitions
int partition(int arr[], int low, int high){
  // last Element becomes pivot
  int pivot = arr[high];
  // i is temporary pivot index - marks the index in the array, where everything with a smaller index (to the left)
  // is already smaller than the pivot itself, but not sorted itself
  int i = (low - 1);

  // for all elements smaller than pivot move them to the left
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
int quickSort(int arr[], int low, int high){
  if (low < high) {
  // partition array and get pivot index
  int pivot = partition(arr, low, high);
  // Sort the two partitions
  quickSort(arr, low, pivot - 1); // sort left side of pivot
  quickSort(arr, pivot + 1, high); // sort right side of pivot
  }
  return 0;
}

// QUICK SORT OF ARRAY OF 'ELEMENT'

int partitionWithElementsByNumber(Element arr[], int low, int high){
  // last Element becomes pivot
  int pivot = (arr+high)->number;
  // i is temporary pivot index - marks the index in the array, where everything with a smaller index (to the left)
  // is already smaller than the pivot itself, but not sorted itself
  int i = (low - 1);

  // for all elements smaller than pivot move them to the left
  for (int j = low; j < high; j++){
    if ((arr+j)->number <= pivot){
       // move temporary pivot index forward
      i++;
      // swap current element with the element at the temporary pivot
      swapElements(arr+i, arr+j);
    }
  }
  // move the pivot element to the correct pivot position (between smaller and larger elements)
  swapElements(arr+i+1, arr+high);
  return (i+1);
}

int partitionWithElementsByLetters(Element arr[], int low, int high) {
  // last Element becomes pivot
  char *pivot = (arr+high)->letters;
  // i is temporary pivot index - marks the index in the array, where everything with a smaller index (to the left)
  // is already smaller than the pivot itself, but not sorted itself
  int i = (low - 1);

  // for all elements smaller than pivot move them to the left
  for (int j = low; j < high; j++){
    if (strcmp(pivot, (arr+j)->letters) >= 0){
       // move temporary pivot index forward
      i++;
      // swap current element with the element at the temporary pivot
      swapElements(arr+i, arr+j);
    }
  }
  swapElements(arr+i+1, arr+high);
  return (i+1);
}

// executes quick sort on array of Element
// either sorting it by numbers or letters depending on kind (either 'l' or 'n')
int quickSortWithElements(Element arr[], int low, int high, bool sortByNumber){
  if (low < high) {
    int pivot;
    if (sortByNumber == true) {
      // partition array and get pivot index sorted by numbers
      pivot = partitionWithElementsByNumber(arr, low, high);
    } else {
      // partition array and get pivot index sorted by letters
      pivot = partitionWithElementsByLetters(arr, low, high);
    }
    // Sort the two partitions
    quickSortWithElements(arr, low, pivot - 1, sortByNumber); // sort left side of pivot
    quickSortWithElements(arr, pivot + 1, high, sortByNumber); // sort right side of pivot
  }
  return 0;
}

// searches for given integer in and array of Element of given size already sorted by numbers
// starts searching in the middle of array and goes left or right depending on target element
int searchForNumber(Element arr[], int target, int size) {
  // first choose middle of array
  int middle;
  // if size is even, middle is offset by 1 to the right
  // if size is odd, int devision by 2 rounds down automatically
  middle = size / 2;

  // exit condition for recursive function
  if (size <= 0) {
    printf("Element was not found.\n");
    return 0;
  }
  // check if selected middle is already the target element
  if ((arr+middle)->number == target) {
    printf("Found it!\n");
    printf("Number: %d - Letters: %s\n", (arr+middle)->number, (arr+middle)->letters);
  } // if target is bigger than middle call searchForNumber on right half of the array
  else if ((arr+middle)->number < target) {
    searchForNumber(arr+middle, target, size - middle);
  } // if target is smaller than middle call searchForNumber on left half of the array
  else if ((arr+middle)->number > target) {
    searchForNumber(arr, target, middle);
  }
  return 0;
}

// searches for given string sequence in array of Element of given size already sorted by letters
// starts searching in the middle of array and goes left or right depending on target element
int searchForLetters(Element arr[], char target[], int size) {
  // first choose middle of array
  int middle;
  // if size is even, middle is offset by 1 to the right
  // if size is odd, int division by 2 rounds down automatically
  middle = size / 2;

  // exit condition for recursive function
  if (size <= 0) {
    printf("Element was not found.\n");
    return 0;
  }

  // check if selected middle is already the target element
  if (strcmp((arr+middle)->letters, target) == 0) {
    printf("Found one!\n");
    printf("Number: %d - Letters: %s\n", (arr+middle)->number, (arr+middle)->letters);
  } else if (strcmp(target, (arr+middle)->letters) > 0) {
    searchForLetters(arr+middle, target, size - middle);
  } else if (strcmp(target, (arr+middle)->letters) < 0) {
    searchForLetters(arr, target, middle);
  }
  return 0;
}

// continiously searches for input from stdin for either a given number or given string sequence in array of Element
int searchForInput(Element arr[], int low, int high) {
  int input = 1;
  while (input != 0) {
    printf("Do you want to search for numbers (type '1') or letters (type '2'):\nOr press '0' to quit.\n");
    scanf("%d", &input);

    switch (input) {
    case 1:;
      int number = 0;
      printf("Type in the number you want to search for:\n");
      scanf("%d", &number);
      quickSortWithElements(arr, low, high-1, true);
      searchForNumber(arr, number, high);
      break;
    case 2:
      printf("Type in the letters (3 upper-case letters only) you want to search for:\n");
      char letters[3];
      scanf("%s", letters);
      quickSortWithElements(arr, low, high-1, false);
      searchForLetters(arr, letters, high);
      break;
    case 0:
      printf("Quitting...\n");
      break;
    default:
      fprintf(stderr, "Error: Did not provide valid input - choose either '1' or '2'\n");
      return 1;
      break;
    }
  }
  return 0;
}

// INSERTION SORT WITH LIST

struct Node* insertNode(struct Node* sorted, struct Node* new_node){
  if (sorted == NULL || sorted->data > new_node->data){
    new_node->next = sorted;
    sorted = new_node;
  } else {
    struct Node* current = sorted;
    // find place to insert
    while(current->next != NULL && current->next->data <= new_node->data){
      current = current->next;
    }
    // insert new_node
    new_node->next = current->next;
    current->next = new_node;
  }
  return sorted;
}

struct Node* listInsertionSort(struct Node* head){
  struct Node* sorted = NULL;
  struct Node* current = head;
  while(current != NULL){
    struct Node* temp = current->next;
    sorted = insertNode(sorted, current);
    current = temp;
  }
  return sorted;
}

// HELPER FUNCTIONS

int executeSort(char name[], int arr[], int length) {
  if (strcmp(name,bub) == 0) {
      printf("bub\n");
      bubbleSort(arr, length);
    } else if (strcmp(name, ins) == 0) {
      printf("ins\n");
      insertionSort(arr, length);
    } else if (strcmp(name, mer) == 0) {
      printf("mer\n");
      mergeSort(arr, 0, (length-1));
    } else if (strcmp(name, qui) == 0) {
      printf("qui\n");
      quickSort(arr, 0, (length-1));
    } else {
      fprintf(stderr, "Error. No valid sort function was specified - Use one of: 'Bubblesort', 'Insertionsort', 'Mergesort', 'Quicksort'");
      return 1;
    }
    return 0;
}

clock_t measureSort(char name[], int array_of_inputs[], int length) {
  clock_t start_t, end_t, total_t;
  start_t = clock();
  executeSort(name, array_of_inputs, length);
  end_t = clock();
  total_t = (double)(end_t - start_t);
  return total_t;
}