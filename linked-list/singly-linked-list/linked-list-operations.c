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
    if (*head == NULL) {
        printf("Empty List\n");
        return;
    }
    struct node *temp = *head;
    if (position == 1) {
        *head = (*head)->next;
        free(temp);
        return;
    }
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid Position\n");
        return;
    }
    struct node *temp1 = temp->next;
    temp->next = temp->next->next;
    free(temp1);
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
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid Position\n");
        return;
    }
    struct node *temp1 = temp->next;
    temp->next = temp->next->next;
    free(temp1);
}


// Traversal

void traverse(struct node *head) {
    if (head == NULL) {
        printf("Empty List\n");
        return;
    }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
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

    // menu
    int choice, data, after, position;
    while (1) {
        printf("\n-----------------------\nMENU:\n\
1. Insert at beginning\n\
2. Insert at end\n\
3. Insert after\n\
4. Insert at position\n\
5. Delete at beginning\n\
6. Delete at end\n\
7. Delete after\n\
8. Delete at position\n\
9. Traverse\n\
10. Search\n\
11. Exit\n\
-----------------------\
\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter after: ");
                scanf("%d", &after);
                insertAfter(head, data, after);
                break;
            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 5:
                deleteAtBeginning(&head);
                break;
            case 6:
                deleteAtEnd(&head);
                break;
            case 7:
                printf("Enter after: ");
                scanf("%d", &after);
                deleteAfter(head, after);
                break;
            case 8:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 9:
                traverse(head);
                break;
            case 10:
                printf("Enter data: ");
                scanf("%d", &data);
                if (search(head, data)) {
                    printf("Found\n");
                } else {
                    printf("Not Found\n");
                }
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
}
}