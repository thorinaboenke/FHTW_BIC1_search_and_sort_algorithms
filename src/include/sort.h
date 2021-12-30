#ifndef SORT_H
#define SORT_H

int bubbleSort(int arr[], int length);
int bubbleSortDescending(int arr[], int length);
int insertionSort(int arr[], int length);
int merge(int arr[], int low, int middle, int high);
int mergeSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
int quickSort(int arr[], int low, int high);

struct Node* listInsertionSort(struct Node* head);
struct Node* insertNode(struct Node* sorted, struct Node* new_node);

#endif
