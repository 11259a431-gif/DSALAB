#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

// Push
void push(int value)
{
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = value;
}

// Pop
void pop()
{
    if (top == -1)
        printf("Stack Underflow\n");
    else
        printf("Popped: %d\n", stack[top--]);
}

// Peek
void peek()
{
    if (top == -1)
        printf("Stack is empty\n");
    else
        printf("Top element: %d\n", stack[top]);
}

int main()
{
    push(10);
    push(20);
    push(30);

    peek();

    pop();

    peek();

    return 0;
}