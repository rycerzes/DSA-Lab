#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct stack {
    struct node* top;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(struct stack* s, int data) {
    struct node* new_node = create_node(data);
    new_node->next = s->top;
    s->top = new_node;
}

int pop(struct stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    int data = s->top->data;
    struct node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return data;
}

int is_empty(struct stack* s) {
    return s->top == NULL;
}

void display(struct stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct node* temp = s->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct stack s;
    s.top = NULL;
    int choice, data;
    do {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. IsEmpty\n");
        printf("4. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(&s, data);
                break;
            case 2:
                data = pop(&s);
                if (data != -1) {
                    printf("Popped data: %d\n", data);
                }
                break;
            case 3:
                if (is_empty(&s)) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 4:
                display(&s);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);
    return 0;
}
