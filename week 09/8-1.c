#include <stdio.h>
#define MAX_SIZE 10

int deque[MAX_SIZE];
int front = -1, rear = -1;

void insertFront(int item) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
        printf("Deque is full. Cannot insert.\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        deque[front] = item;
    } else if (front == 0) {
        front = MAX_SIZE - 1;
        deque[front] = item;
    } else {
        front--;
        deque[front] = item;
    }
}

void insertRear(int item) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
        printf("Deque is full. Cannot insert.\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        deque[rear] = item;
    } else if (rear == MAX_SIZE - 1) {
        rear = 0;
        deque[rear] = item;
    } else {
        rear++;
        deque[rear] = item;
    }
}

void deleteFront() {
    if (front == -1 && rear == -1) {
        printf("Deque is empty. Cannot delete.\n");
    } else if (front == rear) {
        printf("Deleted item: %d\n", deque[front]);
        front = rear = -1;
    } else if (front == MAX_SIZE - 1) {
        printf("Deleted item: %d\n", deque[front]);
        front = 0;
    } else {
        printf("Deleted item: %d\n", deque[front]);
        front++;
    }
}

void deleteRear() {
    if (front == -1 && rear == -1) {
        printf("Deque is empty. Cannot delete.\n");
    } else if (front == rear) {
        printf("Deleted item: %d\n", deque[rear]);
        front = rear = -1;
    } else if (rear == 0) {
        printf("Deleted item: %d\n", deque[rear]);
        rear = MAX_SIZE - 1;
    } else {
        printf("Deleted item: %d\n", deque[rear]);
        rear--;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Deque is empty.\n");
    } else {
        printf("Deque elements: ");
        int i = front;
        while (i != rear) {
            printf("%d ", deque[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", deque[rear]);
    }
}

int peek() {
    if (front == -1 && rear == -1) {
        printf("Deque is empty.\n");
        return -1;
    } else {
        return deque[front];
    }
}

int isFull() {
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty() {
    if (front == -1 && rear == -1) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(int item) {
    if (isFull()) {
        printf("Deque is full. Cannot enqueue.\n");
    } else {
        if (front == -1 && rear == -1) {
            front = rear = 0;
        } else if (rear == MAX_SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        deque[rear] = item;
    }
}

int main() {
    int choice, item;

    do {
        printf("\nDeque Menu\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display Deque\n");
        printf("6. Peek\n");
        printf("7. Is Full\n");
        printf("8. Is Empty\n");
        printf("9. Enqueue\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to insert: ");
                scanf("%d", &item);
                insertFront(item);
                break;
            case 2:
                printf("Enter the item to insert: ");
                scanf("%d", &item);
                insertRear(item);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Peek item: %d\n", peek());
                break;
            case 7:
                if (isFull()) {
                    printf("Deque is full.\n");
                } else {
                    printf("Deque is not full.\n");
                }
                break;
            case 8:
                if (isEmpty()) {
                    printf("Deque is empty.\n");
                } else {
                    printf("Deque is not empty.\n");
                }
                break;
            case 9:
                printf("Enter the item to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 10:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 10);

    return 0;
}
