#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

/* Insert at end */
struct node* insertEnd(struct node *head, int val) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    newnode->data = val;
    newnode->next = NULL;

    if (head == NULL)
        return newnode;

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    return head;
}

/* Display list */
void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

/* Sort linked list */
void sortList(struct node *head) {
    struct node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

/* Reverse linked list */
struct node* reverseList(struct node *head) {
    struct node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

/* Concatenate two lists */
struct node* concatenate(struct node *head1, struct node *head2) {
    if (head1 == NULL)
        return head2;

    struct node *temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}

int main() {
    struct node *head1 = NULL, *head2 = NULL;
    int n, val, i;

    printf("Enter number of elements for List 1: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter element %d for List 1: ", i + 1);
        fflush(stdout);
        scanf("%d", &val);
        head1 = insertEnd(head1, val);
    }

    printf("Enter number of elements for List 2: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter element %d for List 2: ", i + 1);
        fflush(stdout);
        scanf("%d", &val);
        head2 = insertEnd(head2, val);
    }

    printf("\nList 1: ");
    display(head1);

    printf("List 2: ");
    display(head2);

    sortList(head1);
    printf("\nSorted List 1: ");
    display(head1);

    head1 = reverseList(head1);
    printf("Reversed List 1: ");
    display(head1);

    head1 = concatenate(head1, head2);
    printf("Concatenated List: ");
    display(head1);

    return 0;
}