// write a c program to perform polynomial addition of two polynomial using liked list and it should be menu driven

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};


struct node *create(struct node *head)
{
    struct node *new_node, *ptr;
    int num, i;
    printf("Enter the number of terms: ");
    scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        printf("Enter the coefficient: ");
        scanf("%d", &new_node->coeff);
        printf("Enter the exponent: ");
        scanf("%d", &new_node->exp);
        new_node->next = NULL;
        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
        }
    }
    return head;
}


struct node *add(struct node *head1, struct node *head2, struct node *head3)
{
    struct node *ptr1, *ptr2;
    ptr1 = head1;
    ptr2 = head2;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->exp == ptr2->exp)
        {
            head3 = insert(head3, ptr1->coeff + ptr2->coeff, ptr1->exp);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->exp > ptr2->exp)
        {
            head3 = insert(head3, ptr1->coeff, ptr1->exp);
            ptr1 = ptr1->next;
        }
        else
        {
            head3 = insert(head3, ptr2->coeff, ptr2->exp);
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != NULL || ptr2 != NULL)
    {
        if (ptr1 != NULL)
        {
            head3 = insert(head3, ptr1->coeff, ptr1->exp);
            ptr1 = ptr1->next;
        }
        if (ptr2 != NULL)
        {
            head3 = insert(head3, ptr2->coeff, ptr2->exp);
            ptr2 = ptr2->next;
        }
    }
    return head3;
}


struct node *insert(struct node *head, int coeff, int exp)
{
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->coeff = coeff;
    new_node->exp = exp;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    return head;
}


void display(struct node *head)
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%dx^%d", ptr->coeff, ptr->exp);
        ptr = ptr->next;
        if (ptr != NULL)
        {
            printf(" + ");
        }
    }
    printf("Enter any key to continue...");
    getch();
}


int main()
{
    struct node *head1 = NULL, *head2 = NULL, *head3 = NULL;
    int choice;
    while (1)
    {
        system("cls");
        printf("1. Create first polynomial\n\
2. Create second polynomial\n\
3. Add two polynomial\n\
4. Display first polynomial\n\
5. Display second polynomial\n\
6. Display result\n\
7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head1 = create(head1);
            break;
        case 2:
            head2 = create(head2);
            break;
        case 3:
            head3 = add(head1, head2, head3);
            break;
        case 4:
            display(head1);
            break;
        case 5:
            display(head2);
            break;
        case 6:
            display(head3);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}



