#include <stdio.h>
#include <stdlib.h>


int* array_input(int *size, char *message){
    // initializing variables
    int *array;
    // reading the size of the array from the user
    printf("Enter the size of the array:\n--> ");
    scanf("%d", size);

    // initializing the array of size 'size'
    array = (int *)malloc(*size*sizeof(int)); // using *size to access the size(value) of the array

    // reading the elements of the array from the user
    printf("\n%s:\n", message);
    for(int i = 0; i < * size; i++){
        printf("array[%d]: ", i);
        scanf("%d", &array[i]); 
    }

    return array;
}

void print_array(int *array, int size){
    for (int i = 0; i < size; i++){
        printf("array[%d]: %d\n", i, array[i]);
    }
}


int main()
{
    int size, *array;
    array = array_input(&size, "Enter the elements:");
    print_array(array, size);

}