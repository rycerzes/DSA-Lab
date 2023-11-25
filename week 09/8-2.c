#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node* create(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct Node** front, int data, int priority) {
    struct Node* newNode = create(data, priority);

    if (*front == NULL || priority < (*front)->priority) {
        newNode->next = *front;
        *front = newNode;
    } else {
        struct Node* temp = *front;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void dequeue(struct Node** front) {
    if (*front == NULL) {
        printf("Priority queue is empty.\n");
    } else {
        struct Node* temp = *front;
        *front = (*front)->next;
        free(temp);
    }
}

void traverse(struct Node* front) {
    if (front == NULL) {
        printf("Priority queue is empty.\n");
    } else {
        printf("Priority queue elements: ");
        while (front != NULL) {
            printf("%d ", front->data);
            front = front->next;
        }
        printf("\n");
    }
}

int main() {
    struct Node* front = NULL;
    int choice, data, priority;

    do {
        printf("Priority Queue:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to be enqueued: ");
                scanf("%d", &data);
                printf("Enter the priority of the data: ");
                scanf("%d", &priority);
                enqueue(&front, data, priority);
                break;
            case 2:
                dequeue(&front);
                break;
            case 3:
                traverse(front);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
