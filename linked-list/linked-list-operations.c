#include "stdio.h"
#include "stdlib.h"

struct node {
    int data;
    struct node *next;
};

// Insertion in singly linked list


void insertAtBeginning(struct node **head, int data) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct node **head, int data) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAfter(struct node *head, int data, int after) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    struct node *temp = head;
    while (temp != NULL && temp->data != after) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Empty List\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}


void insertAtPosition(struct node **head, int data, int position) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct node *temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid Position\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Deletion

void deleteAtBeginning(struct node **head) { 
    if (*head == NULL) {
        printf("Empty List\n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAtEnd(struct node **head) {
    if (*head == NULL) {
        printf("Empty List\n");
        return;
    }
    struct node *temp = *head;
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(struct node **head, int position) {
    


// Traversal

void traverse(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("Empty List");
}

// Search

int search(struct node *head, int data) {
    struct node *temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// driver code
int main(){
    // initializing liked list
    struct node *head = NULL;

    // inserting elements
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);

    // traversing linked list
    traverse(head);

    // inserting element at position
    insertAtPosition(&head, 5, 3);
    traverse(head);

    // inserting element after a given element
    insertAfter(head, 6, 3);
    traverse(head);

    // deleting element at beginning
    deleteAtBeginning(&head); 
    traverse(head);

    // deleting element at end
    deleteAtEnd(&head);
    traverse(head);

    // d

    // searching element
    if (search(head, 5)) {
        printf("Element Found");
    } else {
        printf("Element Not Found");
    }

}
