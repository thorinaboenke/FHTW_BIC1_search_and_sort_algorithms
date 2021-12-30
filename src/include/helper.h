#ifndef HELPER_H
#define HELPER_H

struct Node {
  int data;
  struct Node* next;
};

void swap (int *a, int *b);

int * initializeArray(int size);

int checkAscending(int arr[], int length);

void printArray(int arr[], int length);

struct Node* getNewNode();

struct Node* initializeList();

void printList(struct Node* head);

void deleteList(struct Node* head);

#endif