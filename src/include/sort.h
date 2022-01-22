#ifndef SORT_H
#define SORT_H

extern char bub[];
extern char ins[];
extern char mer[];
extern char qui[];

int bubbleSort(int arr[], int length);
int bubbleSortDescending(int arr[], int length);
int insertionSort(int arr[], int length);
int merge(int arr[], int low, int middle, int high);
int mergeSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
int quickSort(int arr[], int low, int high);
int searchForInput(Element arr[], int low, int high);
int searchForInputStdLib(Element arr[], int low, int high);
int executeSort(char name[], int arr[], int length);
clock_t measureSort(char name[], int array_of_inputs[], int length);

struct Node* listInsertionSort(struct Node* head);
struct Node* insertNode(struct Node* sorted, struct Node* new_node);

#endif
