#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int data) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = data;
    printf("%d enqueued to queue\n", data);
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("%d dequeued from queue\n", queue[front]);
    front++;
    if (front > rear) {
        front = rear = -1;
    }
}

void traverse() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int is_empty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}

int is_full() {
    if (rear == MAX_SIZE - 1) {
        return 1;
    }
    return 0;
}

int main() {
    int choice, data;
    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. IsEmpty\n");
        printf("5. IsFull\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
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
                if (is_empty()) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 5:
                if (is_full()) {
                    printf("Queue is full\n");
                } else {
                    printf("Queue is not full\n");
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}