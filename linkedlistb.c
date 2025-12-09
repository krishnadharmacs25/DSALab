#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Create list
void createList(int n) {
    int value;
    struct node *newNode, *temp;

    for (int i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

// Display list
void displayList() {
    struct node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Delete first node
void deleteFirst() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
}

// Delete last node
void deleteLast() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head, *prev = NULL;

    if (head->next == NULL) {  
        free(head);
        head = NULL;
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

// Delete specific node
void deleteValue(int value) {
    struct node *temp = head, *prev = NULL;

    if (temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

int main() {
    int n;

    printf("Enter number of nodes to create: ");
    scanf("%d", &n);

    createList(n);
    displayList();

    printf("\ndeleting first node...\n");
    deleteFirst();
    displayList();

    printf("\ndeleting last node...\n");
    deleteLast();
    displayList();

    printf("\ndeleting node with value 20...\n");
    deleteValue(20);
    displayList();

    return 0;
}