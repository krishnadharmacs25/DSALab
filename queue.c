#include <stdio.h>
#define MAX 3     // queue size kept 3 to match your output

int queue[MAX];
int front = -1, rear = -1;

void insert(int x)
{
    if (rear == MAX - 1)
    {
        printf("queue is overflow cannot insert %d\n", x);
        return;
    }
    if (front == -1)
        front = 0;

    queue[++rear] = x;
    printf("inserted %d into queue\n", x);
}

void delete()
{
    if (front == -1 || front > rear)
    {
        printf("queue is empty\n");
        return;
    }
    printf("The deleted element is %d\n", queue[front]);
    front++;
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("queue is empty\n");
        return;
    }

    printf("\nqueue elements\n");
    for (int i = front; i <= rear; i++)
        printf("%d\n", queue[i]);
    printf("\n");
}

int main()
{
    insert(7);
    insert(77);
    insert(56);
    insert(5);   // this will overflow

    display();

    delete();
    delete();
    delete();

    display();

    return 0;
}