#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// TODO: do we have to declare these two strucuts in this file and the header file too?
struct Node {
  int data;
  struct Node* next;
};

typedef struct Element {
  int number;
  char letters[3];
} Element;

Element * initializeArrayOfElements(int size) {
  time_t t;
  srand((unsigned) time(&t));

  // TODO maybe there is a better way to create a random string sequence?
  const char* alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  Element *new_array = (Element *)malloc(sizeof(Element)*size);
  if (new_array == NULL){
    printf("Memory allocation failed");
    exit(1);
  }

  // fill each array element with a random number and a random string sequence
  for (int i = 0; i < size; i++) {
    (new_array+i)->number = (int)(rand() % 32767);

    // create a random character from 'aphabet' for the size of struct Element member 'letters'
    for (int j = 0; j < sizeof(new_array->letters); j++) {
      int tmp = rand() % 26;
      (new_array+i)->letters[j] = alphabet[tmp];
    }
  }
  return new_array;
}

void printArrayOfElements(Element arr[], int length) {
  for (int i = 0; i < length; i++){
    printf("Element %d: numbers: %d - letters: %s\n", i, (arr+i)->number, (arr+i)->letters);
    if ( i != 0 && (i+1) % 15 == 0){
      printf("\n");
    }
  }
  printf("\n");
}

// helper function to swap array elements
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

//function to initialize array, allocate memory dynamically and return a int pointer to start address
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

// helper function to check if array is sorted in ascending order
int checkAscending(int arr[], int length){
  for (int i = 0; i < length-1; i++){
    if ( arr[i] > arr[i+1]){
      printf("Array is not sorted\n");
      return 0;
    }
  }
  return 0;
}

void printArray(int arr[], int length){
  for (int i = 0; i < length; i++){
    printf("%d ", arr[i]);
    if ( i != 0 && (i+1) % 15 == 0){
      printf("\n");
    }
  }
  printf("\n");
}

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

struct Node* getNewNode(int data){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

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

void deleteList(struct Node* head){
  struct Node *temp;
  while(head != NULL){
  temp = head;
  head = head->next;
  free(temp);
  }
}
