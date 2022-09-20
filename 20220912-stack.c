#include<stdio.h>

// stack operations
// push
int push(int *stack, int top, int maxStack, int item);

// pop
int pop(int *stack, int top);

// peek
int peek(int *stack, int top);

// traverse
int traverse(int *stack, int top);



int main(){
     // initializing the stack
        int maxStack = 0;
        printf("Enter the size of the stack:\n --> ");
        scanf("%d", &maxStack);
        int stack[maxStack];
        int top = -1, item = 0;
    while(1){

        // initializing the menu
        int menu = 0;
        printf("\n\nSTACK OPERATIONS\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Traverse\n");
        printf("5. Exit\n\n");
        printf("Choose an operation:\n --> ");
        scanf("%d", &menu);

        // switch case for menu
        switch (menu)
        {
            case 1:
                // initializing the item to be pushed
                printf("Enter the item to be pushed:\n --> ");
                scanf("%d", &item);
                top = push(stack, top, maxStack, item);
                break;
            case 2:
                top = pop(stack, top);
                break;
            case 3:
                printf("Top item is: %d:", peek(stack, top));
                break;
            case 4:
                traverse(stack, top);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}


// push
int push(int *stack, int top, int maxStack,int item){
    if(top == maxStack){
        printf("Stack Overflow\n");
        return top;
    }
    else{
        top++;
        stack[top] = item;
        return top;
    }
}

// pop
int pop(int *stack, int top){
    if(top == -1){
        printf("Stack Underflow\n");
        return top;
    }
    else{
        top--;
        return top;
    }
}

// peek
int peek(int *stack, int top){
    if(top == -1){
        printf("Stack Underflow\n");
        return top;
    }
    else{
        return stack[top];
    }
}

// traverse
int traverse(int *stack, int top){
    if(top == -1){
        printf("Stack Underflow\n");
        return top;
    }
    else{
        for(int i = 0; i <= top; i++){
            printf("stack[%d] = %d\n", i, stack[i]);
        }
        return top;
    }
}