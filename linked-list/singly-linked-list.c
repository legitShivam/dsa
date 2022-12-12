#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *next;
} node;


node* create(int number_of_nodes){
    node *head = malloc(sizeof(node));
    if(number_of_nodes == 1){
        return head;
    }

    node *ptr = head;
    for(int i=0; i<number_of_nodes-1; i++){
        ptr->next = malloc(sizeof(node));
        ptr = ptr->next;
    }

    return head;
}


int count(node *head){
    int count = 0;
    if(head == NULL){
        return count;
    }
    else{
        node *ptr = head;
        while(ptr != NULL){
            count ++;
            ptr = ptr->next;
        }
    }

    return count;
}


node* insert(node *head, int data){

    if(head == NULL){
    head = malloc(sizeof(node));
    head->data = data;
    } 
    else{
        node *temp = malloc(sizeof(node));
        temp->data = data;
        temp->next = head;
        head = temp;
    }

    return head;
}

void print(node *head){
    if(head == NULL){
        printf("List is empty!");
    }
    else{
        node *ptr = head;
        printf("Head->");
        while(ptr != NULL){
            printf("[%d]->", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

node* append(node *head, int data){
    node *ptr, *temp;
    ptr = head;
    temp = (node*) malloc(sizeof(node));
    temp->data = data;

    if(head == NULL){
        head = temp;
        ptr = temp;
    }
    else{
        while(ptr->next != NULL){
            ptr = ptr->next;
        }

        ptr->next = temp;
    }

    return head;
}


int main(){
    ;

    node *list = create(2); 
    list = insert(list, 13);
    list = append
    
    
    (list, 53);



    // for(int i=0; i< 3; i++){
    // }

    int total_nodes = count(list);
    printf("Total number of nodes = %d\n", total_nodes);
    print(list);



}
