#include <stdio.h>
#define max 5

int stack[max];
int top = -1;

// push operation
void push(int value) {
    if (top == max - 1) {
        printf("Stack overflow! cannot push\n");
    } else {
        stack[++top] = value;
        printf("%d pushed into the stack\n", value);
    }
}

// pop operation
void pop() {
    if (top < 0) {
        printf("Stack underflow! nothing left to pop\n");
    } else {
        printf("%d popped from the stack\n", stack[top--]);
    }
}

// display operation
void display() {
    if (top < 0) {
        printf("Stack is empty\n");
    } else {
        printf("Stack contents (top to bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, value;

    do {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}