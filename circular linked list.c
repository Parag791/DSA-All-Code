#include <stdio.h>
#include <stdlib.h>

// structure for a node
struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to create circular linked list
struct Node* createCircularList(int n) {
    struct Node *head = NULL, *temp, *newNode;
    int data, i;

    if (n <= 0) {
        return NULL;
    }

    printf("Enter info of node1: ");
    scanf("%d", &data);
    head = createNode(data);
    head->next = head;  // circular connection
    temp = head;

    for (i = 2; i <= n; i++) {
        printf("Enter info of node%d: ", i);
        scanf("%d", &data);
        newNode = createNode(data);
        temp->next = newNode;
        newNode->next = head;  // point last node back to head
        temp = newNode;
    }

    return head;
}

// function to display circular linked list
void display(struct Node* head) {
    struct Node* temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Clinkedlist: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int n;
    struct Node* head = NULL;

    printf("Enter no. of nodes: ");
    scanf("%d", &n);

    head = createCircularList(n);
    display(head);

    return 0;
}
