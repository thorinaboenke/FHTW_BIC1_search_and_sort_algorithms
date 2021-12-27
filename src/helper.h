#ifndef HELPER_H
#define HELPER_H

/******************************************************************************
 *      swap                                                                  *
 *      @brief swaps two elements in an array                                 *
 *                                                                            *
 *      This function swaps two elements in an array                          *
 *                                                                            *
 *      @param a                address of first element                      *
 *      @param b                address of second element                     *
 *      @retval                                                               *
 ******************************************************************************/
void swap (float *a, float *b);


/******************************************************************************
 *      initializeArray                                                       *
 *      @brief initializes an array of floats                                 *
 *                                                                            *
 *      This function initializes an array of floats                          *
 *                                                                            *
 *      @param size              size of array                                *
 *      @retval                                                               *
 ******************************************************************************/
float * initializeArray(int size);

/******************************************************************************
 *      checkAscending                                                        *
 *      @brief Checks if an Array is sorted in ascending order                *
 *                                                                            *
 *      This function checks if an Array is sorted in ascending order         *
 *                                                                            *
 *      @param arr              array of floats                               *
 *      @param length           size of array                                 *
 *      @retval                                                               *
 ******************************************************************************/

int checkAscending(float arr[], int length);

void printArray (float arr[], int length);

#endif