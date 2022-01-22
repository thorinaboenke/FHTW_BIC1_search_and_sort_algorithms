#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

struct Node {
  int data;
  struct Node* next;
};

typedef struct Element {
  int number;
  char letters[4];
} Element;

Element * initializeArrayOfElements(int size) {
  time_t t;
  srand((unsigned) time(&t));
  Element *new_array = (Element *)malloc(sizeof(Element)*size);
  if (new_array == NULL){
    printf("Memory allocation failed");
    exit(1);
  }

  // fill each array element with a random number and a random string sequence
  for (int i = 0; i < size; i++) {
    (new_array+i)->number = (int)(rand() % 32767);

    // create a random character (ASCII between 65 and 90) for the size of struct Element member 'letters'
    for (int j = 0; j < (int)sizeof(new_array->letters); j++) {
      (new_array+i)->letters[j] = 65 + (rand() % 26);
    }
    (new_array+i)->letters[3] = '\0';

  }
  return new_array;
}

// iterates over an Array of structs Element and prints them out
void printArrayOfElements(Element arr[], int length) {
  for (int i = 0; i < length; i++){
    printf("Element %d: numbers: %d - letters: %s\n", i, (arr+i)->number, (arr+i)->letters);
    if ( i != 0 && (i+1) % 15 == 0){
      printf("\n");
    }
  }
  printf("\n");
}

// helper function to swap array elements in an array of integers
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
  }

// helper function to swap elements in array of struct 'Element'
void swapElements(Element *a, Element *b) {
  Element temp = *a;
  *a = *b;
  *b = temp;
}

// function to initialize integer array, allocates memory dynamically and returns a pointer to start address
// always uses the same pseudo random numbers
int * initializeArray(int size) {
  // seed random function always with the same value so the same numbers are generated
  srand(1);

  int *new_array = (int *)malloc(sizeof(int)*size);
  if (new_array == NULL){
    printf("Memory allocation failed");
    exit(1);
  }

  for(int i = 0; i < size; i++) {
  int random_number = (int)(rand() % 32767);

  if (rand() % 2 == 1) {
    random_number *= -1;
  }
  new_array[i] = random_number;
  }
  return new_array;
}

// helper function to check if integer array is sorted in ascending order
// prints message to the console if array is not sorted correctly
int checkAscending(int arr[], int length){
  for (int i = 0; i < length-1; i++){
    if ( arr[i] > arr[i+1]){
      printf("Array is not sorted\n");
      return 0;
    }
  }
  return 0;
}

// iterates over an array of integers arr of size length and prints out all elements
// max 15 per line
void printArray(int arr[], int length){
  for (int i = 0; i < length; i++){
    printf("%d ", arr[i]);
    if ( i != 0 && (i+1) % 15 == 0){
      printf("\n");
    }
  }
  printf("\n");
}

// traverses a linked list and prints all elements from a linked list of Nodes
void printList(struct Node * head){
  int count = 0;
  if (head == NULL){
    return;
  }
  while (head != NULL){
    printf("%d ", head->data);
    head = head->next;
    count++;
    if(count % 15 == 0){
       printf("\n");
    }
  }
  printf("\n");
  return;
}

// dynamically allocates memory for a new node
// initializes data field with the integer passed as function paramter
// returns pointer to the new node
struct Node* getNewNode(int data){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// initializes linked list of nodes of a given size length
// returns pointer to the head node
struct Node* initializeList(int length, int arr[]){
  struct Node* head = getNewNode(arr[0]);
  struct Node* current = head;
  for(int i = 1; i<length; i++){
    struct Node* newNode = getNewNode(arr[i]);
    current->next = newNode;
    current = newNode;
  }
  return head;
}

// deletes all element in a linkes list of Nodes
void deleteList(struct Node* head){
  struct Node *temp;
  while(head != NULL){
    temp = head;
    head = head->next;
    free(temp);
  }
}
// compare functions for numbers for stdlib qsort()
int compareElementsByNumber(const void *El1, const void *El2){
  Element *C1 = (Element *)El1;
  Element *C2 = (Element *)El2;
  return (C1->number - C2->number);
}

// compare functions for strings for stdlib qsort()
int compareElementsByLetters(const void *El1, const void *El2){
  Element *E1 = (Element *)El1;
  Element *E2 = (Element *)El2;
  return strcmp(E1->letters, E2->letters);
}


// compare functions for strings for stdlib bsearch()
int compareStringToElement(const void *s, const void *d) {
  return strncmp(s, ((const Element *)d)->letters, sizeof(((Element *)0)->letters));
}

// compare functions for numbers for stdlib bsearch()
int compareNumberToElement(const void *s, const void *d) {
  int *C1 = (int *)s;
  Element *C2 = (Element *)d;
  return (*C1 - C2->number);
  // alternatively
  //return (*(int*)s - C2->number);
}
