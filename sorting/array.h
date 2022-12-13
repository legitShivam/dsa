#include <stdio.h>


void swap(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}


void printArray(int array[], int size){
    for(int i=0; i<size; i++){
        printf("%d, ", array[i]);
    }
    printf("\n");
}