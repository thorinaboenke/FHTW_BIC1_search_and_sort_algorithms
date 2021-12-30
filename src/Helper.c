#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct Node {
  int data;
  struct Node* next;
};

// helper function to swap array elements
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
  }

//function to initialize array, allocate memory dynamically and return a int pointer to start address
int * initializeArray(int size) {

  srand((unsigned int) time(NULL));

  int *new_array = (int *)malloc(sizeof(int)*size);

  for(int i = 0; i < size; i++) {
  int random_number = (int)(rand() % 32767);
  // only 3 decimals

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
