#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int top = -1;
int stack[MAX_SIZE];

void push(int element) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
    } else {
        top++;
        stack[top] = element;
        printf("Element %d pushed to stack\n", element);
    }
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        int element = stack[top];
        top--;
        printf("Element %d popped from stack\n", element);
        return element;
    }
}

bool isEmpty() {
    if (top == -1) {
        return true;
    } else {
        return false;
    }
}

bool isFull() {
    if (top == MAX_SIZE - 1) {
        return true;
    } else {
        return false;
    }
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, element;

    do {
        printf("Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check if stack is empty\n");
        printf("4. Check if stack is full\n");
        printf("5. Display stack elements\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                if (isEmpty()) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 4:
                if (isFull()) {
                    printf("Stack is full\n");
                } else {
                    printf("Stack is not full\n");
                }
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}
