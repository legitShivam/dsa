#include <stdio.h>
#include "array.h"


void bubble_sort(int array[], int size){
    
    for(int i=0; i < size-1; i++){
        for(int j=0; j< size-i-1; j++){
            if(array[j]>array[j+1]){
                swap(&array[j], &array[j+1]);
            }
        }
    }
}



// // driver code
// int main(){
//     // initializing array
//     int array[] = {1, 67, 23, 890, 78, 2, 0};
//     int length = sizeof(array)/sizeof(int);
//     printArray(array, length);

//     //bubble sort
//     bubble_sort(array, length);
//     printArray(array, length);
// }