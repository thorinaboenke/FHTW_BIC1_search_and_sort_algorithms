#ifndef HELPER_H
#define HELPER_H

struct Node {
  int data;
  struct Node* next;
};

typedef struct Element {
  int number;
  char letters[3];
} Element;

void swap (int *a, int *b);
void swapElements(Element *a, Element *b);

int * initializeArray(int size);

Element * initializeArrayOfElements(int size);

int checkAscending(int arr[], int length);

void printArray(int arr[], int length);

void printArrayOfElements(Element arr[], int length);

struct Node* getNewNode();

struct Node* initializeList();

void printList(struct Node* head);

void deleteList(struct Node* head);

int compareElementsByNumber(const void *El1, const void *El2);

int compareElementsByLetters(const void *El1, const void *El2);

int compareStringToElement(const void *s, const void *d);

int compareNumberToElement(const void *s, const void *d);

#endif
