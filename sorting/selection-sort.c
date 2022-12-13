#include <stdio.h>
#include "array.h"

void selection_sort(int array[], int size){
    // loop for the passes
    for(int i=0; i<size-1; i++){
        int *min = &array[i];

        // loop for finding the min(smallest) element
        for(int j=i+1; j<size; j++){
            if(array[j]<*min){
                swap(min, &array[j]);
            }
        }
    }
}


// // driver code
// int main(){
//     // initializing unsorted array
//     int array[] = {1, 67, 23, 890, 78, 2, 0};
//     int length = sizeof(array)/sizeof(int);

//     // printing the unsorted array
//     printArray(array, length);

//     // sorting the array using selection sort
//     selection_sort(array, length);
//     printArray(array, length);
// }