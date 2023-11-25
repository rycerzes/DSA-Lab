#include <stdio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isEmpty() {
    if (front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

int isFull() {
    if ((rear + 1) % MAX_SIZE == front)
        return 1;
    else
        return 0;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue element.\n");
    } else {
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = data;
        printf("Element %d enqueued successfully.\n", data);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue element.\n");
    } else {
        printf("Element %d dequeued successfully.\n", queue[front]);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }
}

void traverse() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        int i = front;
        printf("Elements in the queue: ");
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    int choice, data;

    do {
        printf("\nCircular Queue Operations\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                traverse();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
