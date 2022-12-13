#include<stdio.h>
#include <stdlib.h>
#include "stack.h"


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

    printf("Source rod:\n");
    printStack(&tower);

    hanoi(4, &tower, &aux, &dest);

    printf("\nDest rod:\n");
    printStack(&dest);


}