#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// array io functions
int *input_array(int *size, char *message);
void print_array(int *array, int size);

// insertion functions
void append_elmnt(int *array, int *size, int element);
int insert_elmnt(int *array, int *size, int element, int index);

// deletion functions
int pop_elmnt(int *arr, int *size);
int remove_elmnt(int *arr, int *size, int index);

int main()
{
    int *array, size = 0, choice, element, position = -1, flag;
    while (1)
    {
        // printing the menu
        printf("\n");
        printf("1.Element Insertion at the end\n2.Element Insertion at an Positon\n3.Pop an Element\n4.Delete an Element by Postion\n5.Exit\n\n");
        printf("Enter your choice:\n--> ");

        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
            {
            case 1:
                array = input_array(&size, "Enter the elements of the array:\n");

                // reading the element to be inserted from the user
                printf("\nEnter the element to insert:\n--> ");
                scanf("%d", &element);
                printf("\n");

                // inserting the element at the end of the array
                append_elmnt(array, &size, element);
                printf("Modified array is:\n");
                print_array(array, size);
                break;

            case 2:
                array = input_array(&size, "Enter the elements of the array:\n");

                // reading the element to be inserted from the user
                printf("\nEnter the element to insert:\n--> ");
                scanf("%d", &element);
                printf("\nEnter the position at which you want to insert the element:\n--> ");
                scanf("%d", &position);
                printf("\n");

                // inserting the element at the given index in the arrya
                flag = insert_elmnt(array, &size, element, position - 1);
                if(!flag){
                    printf("Modified array is:\n");
                    print_array(array, size);
                }
                else{
                    printf("Enter a valid position!\n");
                }
                
                break;

            case 3:
                array = input_array(&size, "Enter the elements of the array:\n");

                // removing the element from the end
                flag = pop_elmnt(array, &size);
                if(!flag){
                    printf("Modified array is:\n");
                    print_array(array, size);
                }
                else{
                    printf("Enter a valid position!\n");
                }
                break;

            case 4:
                array = input_array(&size, "Enter the elements of the array:\n");

                // reading the element to be inserted from the user
                printf("\nEnter the position of element you want to remove:\n--> ");
                scanf("%d", &position);
                printf("\n");

                // removing the element from the postion
                flag = remove_elmnt(array, &size, position - 1);
                if(!flag){
                    printf("Modified array is:\n");
                    print_array(array, size);
                }
                else{
                    printf("Enter a valid position!\n");
                }
                break;

            case 5:
                return 0;

            default:
                printf("Wrong choice!!!\n");
                break;
            }
        }
    }
}

// array io functions
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

// insertion functions
void append_elmnt(int *array, int *size, int element)
{
    array = (int *)realloc(array, *size * sizeof(int) + 1);
    *size = *size + 1;
    array[*size - 1] = element;
}

int insert_elmnt(int *array, int *size, int element, int index)
{
    if (index > *size)
    {
        return -1;
    }

    // increasing the size of the array
    array = (int *)realloc(array, *size * sizeof(int) + 1);
    *size = *size + 1;

    // shifting the elements of the array by one postion(1)
    for (int i = index; i < *size; i++)
    {
        array[i + 1] = array[i];
    }

    array[index] = element;

    return 0;
}

// deletion functions
int pop_elmnt(int *array, int *size)
{
    if (*size == 0)
    {
        return -1;
    }
    // decreasing size of the array by one postion
    array = (int *)realloc(array, *size * sizeof(int) - 1);
    *size = *size - 1;

    return 0;
}

int remove_elmnt(int *array, int *size, int index)
{
    if (index > *size)
    {
        return -1;
    }

    // shifting the elements by one postion (-1)
    for (int i = index; i < *size; i++)
    {
        array[i] = array[i+1];
    }

    // decreasing size of the array by one postion
    array = (int *)realloc(array, *size * sizeof(int) - 1);
    *size = *size - 1;

    return 0;
}
