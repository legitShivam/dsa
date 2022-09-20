// Menu driven program to search an element in an array using linear search and binary search and bubble sort

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// array manipulation functions
int *input_array(int *size, char *message);
void print_array(int *array, int size);

// search functions
int linear_search(int *arr, int element, int size);
int binary_search(int *arr, int element, int size);

// sorting functions
void bubble_sort(int *arr, int size);

int main()
{
    int *array, size = 0, choice, element, postion = -1;
    while (1)
    {
        // printing the menu
        printf("\n");
        printf("1.Linear Search\n2.Binary Search\n3.Bubble Sort\n4.Exit\n\n");
        printf("Enter your choice:\n--> ");

        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
            {
            case 1:
                array = input_array(&size, "Enter the elements of the array:\n");

                // reading the element to be searched from the user
                printf("\nEnter the element to search:\n--> ");
                scanf("%d", &element);
                printf("\n");

                // searching the element using linear search
                postion = linear_search(array, element, size);
                printf("Element '%d' is found at postion: %d\n", element, postion + 1);
                break;
            case 2:
                array = input_array(&size, "Enter the element in sorted manner:\n");

                // reading the element to be searched from the user
                printf("\nEnter the element to search:\n--> ");
                scanf("%d", &element);
                printf("\n");

                // searching the element using binary search
                postion = binary_search(array, element, size);
                printf("Element '%d' is found at postion: %d\n", element, postion + 1);
                break;

            case 3:
                array = input_array(&size, "Enter the elements of the array:\n");

                // sorting the array using bubble sort
                bubble_sort(array, size);
                printf("\nThe sorted array is:\n");
                print_array(array, size);
                break;

            case 4:
                return 0;

            default:
                printf("Wrong choice!!!\n");
                break;
            }
        }
    }
}

// array manipulation functions
int *input_array(int *size, char *message)
{
    // initializing variables
    int *array;
    // reading the size of the array from the user
    printf("Enter the size of the array:\n--> ");
    scanf("%d", size);

    // initializing the array of size 'size'
    array = (int *)malloc(*size * sizeof(int)); // using *size to access the size(value) of the array

    // reading the elements of the array from the user
    if(*size > 0) {
        printf("\n%s", message);
        for (int i = 0; i < *size; i++)
        {
            printf("array[%d]: ", i);
            scanf("%d", &array[i]);
        }
    }

    return array;
}

void print_array(int *array, int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

// search functions
int linear_search(int *array, int element, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int binary_search(int *array, int element, int size)
{
    int lowerBound = 0, upperBound = size - 1, mid;
    for (int i = 0; i < size; i++)
    {
        mid = (lowerBound + upperBound) / 2;
        if (array[mid] == element)
        {
            return mid;
        }
        else if (array[mid] > element)
        {
            upperBound = mid - 1;
        }
        else
        {
            lowerBound = mid + 1;
        }
    }
}

// sorting functions
void bubble_sort(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[i] < array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
