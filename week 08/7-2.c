// Write a menu driven program to implement linear queue operations such as
// Enqueue, Dequeue,  IsEmpty, Traverse using single linked list.

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(struct node **front, struct node **rear, int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;
    if (*front == NULL)
    {
        *front = new;
        *rear = new;
    }
    else
    {
        (*rear)->next = new;
        *rear = new;
    }
}

void dequeue(struct node **front, struct node **rear)
{
    if (*front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        struct node *temp = *front;
        *front = (*front)->next;
        free(temp);
    }
}

void traverse(struct node **front, struct node **rear)
{
    if (*front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        struct node *temp = *front;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void isEmpty(struct node **front, struct node **rear)
{
    if (*front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue is not empty\n");
    }
}

int main()
{
    int choice, data;
    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. IsEmpty\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to enqueue: ");
            scanf("%d", &data);
            enqueue(&front, &rear, data);
            break;
        case 2:
            dequeue(&front, &rear);
            break;
        case 3:
            traverse(&front, &rear);
            break;
        case 4:
            isEmpty(&front, &rear);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
