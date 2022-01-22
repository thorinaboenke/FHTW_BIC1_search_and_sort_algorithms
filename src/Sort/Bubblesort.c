#include <stdio.h>
#include <stdlib.h>

// swap adjacent elements if they are in the wrong order
// after one interation the last element is correctly positioned, repeat again until second last element etc.
int bubbleSort(float arr[], int length){
   for (int i = 0; i<length-1; i++) {
     for (int j = 0; j < length-i-1; j++){
       if (arr[j] > arr[j+1]){
         swap (&arr[j], &arr[j+1]);
       }
     }
   }
   return 0;
}
