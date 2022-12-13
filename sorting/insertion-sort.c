#include <stdio.h>
#include "array.h"

void insertion_sort(int array[], int size){
    // loop for passes
    for(int i=1; i < size; i++){
        int key = array[i];
        int j = i-1;

        // loop for inserting into the sorted sub-array
        while(j>=0 && array[j]>key){
            // swap(&array[j], &array[j+1]);
            array[j+1] = array[j];
            j--;
        }

        array[j+1] = key;
    }
}

// // driver code
// int main(){
//     // initializing unsorted array
//     int array[] = {1, 67, 23, 890, 78, 2, 0};
//     int length = sizeof(array)/sizeof(int);

//     // printing the unsorted array
//     printArray(array, length);

//     // sorting the array using insertion sort
//     insertion_sort(array, length);
//     printArray(array, length);
// }