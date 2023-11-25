#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int top = -1;
int stack[MAX_SIZE];

void push(int element) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
    } else {
        top++;
        stack[top] = element;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        int element = stack[top];
        top--;
        return element;
    }
}

void main()
{
    int dec,n,k=0;
    printf("Enter a number: ");
    scanf("%d", &dec);
    n=dec;
   while (n != 0) {
        push(n % 2);
        n = n / 2;
        k++;
    }
    printf("Binary equivalent of %d is: ");
    while (k != -0) {
        printf("%d", pop());
        k--;
    } 
    printf("\n");  
}