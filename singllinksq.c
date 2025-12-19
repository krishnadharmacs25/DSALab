#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

/* ---------- STACK USING SINGLE LINKED LIST ---------- */
struct node *top = NULL;

/* Push */
void push(int val) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    newnode->data = val;
    newnode->next = top;
    top = newnode;
    printf("%d pushed into stack\n", val);
}

/* Pop */
void pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct node *temp = top;
    printf("Popped element: %d\n", temp->data);
    top = top->next;
    free(temp);
}

/* Display Stack */
void displayStack() {
    struct node *temp = top;
    if (temp == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* ---------- QUEUE USING SINGLE LINKED LIST ---------- */
struct node *front = NULL, *rear = NULL;

/* Enqueue */
void enqueue(int val) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    newnode->data = val;
    newnode->next = NULL;

    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    printf("%d enqueued into queue\n", val);
}

/* Dequeue */
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct node *temp = front;
    printf("Dequeued element: %d\n", temp->data);
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
}

/* Display Queue */
void displayQueue() {
    struct node *temp = front;
    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* ---------- MAIN ---------- */
int main() {

    /* Stack Operations */
    printf("STACK OPERATIONS\n");
    push(10);
    push(20);
    push(30);
    displayStack();
    pop();
    displayStack();

    /* Queue Operations */
    printf("\nQUEUE OPERATIONS\n");
    enqueue(5);
    enqueue(15);
    enqueue(25);
    displayQueue();
    dequeue();
    displayQueue();

    return 0;
}