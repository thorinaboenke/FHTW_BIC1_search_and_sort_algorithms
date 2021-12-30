#ifndef SORT_H
#define SORT_H

int bubbleSort(float arr[], int length);
int bubbleSortDescending(float arr[], int length);
int insertionSort(float arr[], int length);
int merge(float arr[], int low, int middle, int high);
int mergeSort(float arr[], int low, int high);
int partition(float arr[], int low, int high);
int quickSort(float arr[], int low, int high);

#endif
