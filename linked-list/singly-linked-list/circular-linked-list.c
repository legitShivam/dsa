#include<stdio.h>

// operations on circular linked list
// insertion
// deletion
// traversal
// search

struct node {
    int data;
    struct node *next;
};


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
        printf("Empty List\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// deletion

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
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAfter(struct node *head, int after) {
    if (head == NULL) {
        printf("Empty List\n");
        return;
    }
    struct node *temp = head;
    while (temp != NULL && temp->data != after) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Empty List\n");
        return;
    }
    struct node *temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
}

void deleteAtPosition(struct node **head, int position) {
    if (*head == NULL) {
        printf("Empty List\n");
        return;
    }
    if (position == 1) {
        struct node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct node *temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Empty List\n");
        return;
    }
    struct node *temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
}

// traversal 

void traverse(struct node *head) {
    if (head == NULL) {
        printf("Empty List\n");
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
    printf("\n");
}

// search

void search(struct node *head, int data) {
    if (head == NULL) {
        printf("Empty List\n");
        return;
    }
    struct node *temp = head;
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Not Found\n");
        return;
    }
    printf("Found\n");
}


// driver code

int main(){
    // menu
    struct node *head = NULL;
    int choice, data, after, position;

    dxdiag
    
}