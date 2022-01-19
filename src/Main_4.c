#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "helper.h"
#include "sort.h"

// function prototypes
void compareArrayAndListInsertionSort();

int main(){
  printf("1.4 Insertion Sort in array vs. lists.\n");
  compareArrayAndListInsertionSort();
  return 0;
}

void compareArrayAndListInsertionSort(){
clock_t start, end, total_array_init, total_array_sort, total_list_init, total_list_sort;
struct Node* head = NULL;

start = clock();
int * array = initializeArray(2048);
end = clock();
total_array_init = (double)(end - start);

start = clock();
head = initializeList(2048, array);
end = clock();
total_list_init = (double)(end - start);

printf("Printing array:\n");
printArray(array, 2048);
printf("\n");
printf("Printing list:\n");
printList(head);
printf("\n");

start = clock();
insertionSort(array, 2048);
end = clock();
total_array_sort = (double)(end - start);

start = clock();
head = listInsertionSort(head);
end = clock();
total_list_sort = (double)(end - start);

printf("Printing sorted array:\n");
printArray(array, 2048);
printf("\n");
printf("Printing sorted list:\n");
printList(head);
printf("\n");
printf("\tInit \tSort\n");
printf("Array: \t%.0lu\t%.0lu microseconds\n", total_array_init, total_array_sort);
printf("List: \t%.0lu\t%.0lu microseconds\n", total_list_init, total_list_sort);

deleteList(head);
free(array);
}
