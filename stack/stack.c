#include<stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int size;
    int *buffer;
    int top;
} Stack;


void initStack(Stack *stk, int size){
    stk->size = size;
    stk->buffer = calloc(size, sizeof(int) * size);
    stk->top = -1;
}


void printStack(Stack *stk){
    if(stk->top == -1){
        printf("Stack is empty\n");
        return;
    }

    for(int i= stk->top; i>=0; i--){
        printf("[%d]\n", stk->buffer[i]);
    }
}


void push(Stack *stk, int element){
    if(stk->top >= stk->size-1){
        printf("Stack overflow!\n");
        return;
    }

    stk->top++;
    stk->buffer[stk->top] = element;
}

int pop(Stack *stk){
    if(stk->top == -1){
        printf("Stack underflow!\n");
        return -1;
    }

    int element = stk->buffer[stk->top];
    stk->top--;

    return element;
}

void peek(Stack *stk){
    printf("[%d]\n", stk->buffer[stk->top]);
}


void hanoi(int number_of_disks, Stack *source, Stack *aux, Stack *dest){
    if(number_of_disks == 1){
        return;
    }

    hanoi(number_of_disks -1, source, dest, aux);
    hanoi(number_of_disks -1, aux, source, dest);

}


int main(){
    // initializing tower of hanoi
    Stack tower, aux, dest;
    initStack(&tower, 50);
    initStack(&aux, 50);
    initStack(&dest, 50);
    push(&tower, 4);
    push(&tower, 5);
    push(&tower, 2);
    push(&tower, 9);

    // printf("Source rod:\n");
    // printStack(&tower);

    hanoi(4, &tower, &aux, &dest);

    printf("\nDest rod:\n");
    printStack(&dest);


}