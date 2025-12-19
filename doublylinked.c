#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

/* Create doubly linked list */
struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newnode;
    int val, i;

    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = val;
        newnode->prev = newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
    return head;
}

/* Insert a new node to the left of a given value */
struct node* insertLeft(struct node *head, int key, int val) {
    struct node *temp = head, *newnode;

    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Key not found\n");
        return head;
    }

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;

    newnode->next = temp;
    newnode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newnode;
    else
        head = newnode;

    temp->prev = newnode;
    return head;
}

/* Delete a node based on specific value */
struct node* deleteNode(struct node *head, int key) {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found\n");
        return head;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    return head;
}

/* Display list */
void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

/* Main function */
int main() {
    struct node *head = NULL;
    int n, key, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    head = createList(n);

    display(head);

    printf("\nEnter value to insert: ");
    scanf("%d", &val);
    printf("Enter node value to insert left of: ");
    scanf("%d", &key);
    head = insertLeft(head, key, val);
    display(head);

    printf("\nEnter value to delete: ");
    scanf("%d", &key);
    head = deleteNode(head, key);
    display(head);

    return 0;
}