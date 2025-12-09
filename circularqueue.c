#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

int isEmpty() {
    return (front == -1);
}

void insert(int x)
{
    if (isFull()) {
        printf("Queue Overflow... cannot insert %d\n", x);
        return;
    }

    if (front == -1)  // First element
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = x;

    printf("%d inserted into queue\n", x);
}

void delete()
{
    if (isEmpty()) {
        printf("Queue is empty... nothing to delete\n");
        return;
    }

    printf("Deleted element is %d\n", queue[front]);

    if (front == rear) {
        front = rear = -1;  // Queue becomes empty
    } else {
        front = (front + 1) % MAX;
    }
}

void display()
{
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");

    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    display();

    delete();
    delete();

    display();

    insert(60);
    insert(70); // these use circular positions

    display();

    return 0;
}