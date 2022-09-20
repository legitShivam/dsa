#include<stdio.h>

struct Stack{
    int maxStack;
    int array[25];
    int top;
}


Stack init(int size){
    Stack temp;
    temp.maxStack = size;
    temp.top = -1;
    
    return temp;
}


int pop(Stack* stack){
    if(stack.max == 0){
        printf("Stack underflow");
        return -1;
    }
    stack.top = stack.top-1;
    return stack.array[stack.top+1]
}


void push(Stack* stack. int element){
    if(stack.top == stack.max){
        printf("Stack overflow");
    }
    stack.top = stack.top + 1;
    stack.array[stack.top] = element;
}


int hanoi(int disk, Stack* source, Stack* aux, Stack* dest){
    if(disk == 1){
        push(dest, pop(source))
    }
    hanoi(disk-1, source, dest, aux);
    push(dest, pop(source));
    hanoi(disk-1, aux, source, dest);
}

//driver
int main(){
    Stack source, aux, dest;

    source = init(5);
    aux = init(5);
    dest = init(5);

    push(&source, 3);
    push(&source, 2);
    push(&source, 1);

    hanoi(3, &source, &aux, &dest);

}