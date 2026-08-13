#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1, size;

void enqueue() {
    int element;
    if ((front == 0 && rear == size - 1) || (rear + 1) % size == front) {
        printf("Queue is Full!\n");
        return;
    }
    printf("Enter element: ");
    scanf("%d", &element);
    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % size;
    queue[rear] = element;
}

void dequeue() {
    if (front == -1) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Element deleted: %d\n", queue[front]);
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % size;
}

void traverse() {
    int i;
    if (front == -1) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("CQueue: ");
    i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % size;
    }
    printf("\n");
}

void isEmpty() {
    if (front == -1)
        printf("Queue Empty: True\n");
    else
        printf("Queue Empty: False\n");
}

void isFull() {
    if ((front == 0 && rear == size - 1) || (rear + 1) % size == front)
        printf("Queue Full: True\n");
    else
        printf("Queue Full: False\n");
}

int main() {
    int choice;
    printf("Enter Queue size: ");
    scanf("%d", &size);

    do {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n2. Dequeue\n3. IsEmpty\n4. IsFull\n5. Traverse\n6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: isEmpty(); break;
            case 4: isFull(); break;
            case 5: traverse(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Structure for polynomial term
struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Function to insert term at end
void insertTerm(struct Node** poly, int coeff, int pow) {
    struct Node* newNode = createNode(coeff, pow);
    if (*poly == NULL) {
        *poly = newNode;
        return;
    }
    struct Node* temp = *poly;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to display polynomial
void display(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->pow);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* addPoly(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow > poly2->pow) {
            insertTerm(&result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow) {
            insertTerm(&result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }
        else {
            insertTerm(&result, poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    // Copy remaining terms
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertTerm(&result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }
    return result;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;

    int maxPow, coeff, i;

    // Polynomial 1
    printf("Polynomial-1:\n");
    printf("Enter the maximum power of x: ");
    scanf("%d", &maxPow);
    for (i = maxPow; i >= 0; i--) {
        printf("Enter coefficient of degree %d: ", i);
        scanf("%d", &coeff);
        if (coeff != 0)
            insertTerm(&poly1, coeff, i);
    }

    // Polynomial 2
    printf("Polynomial-2:\n");
    printf("Enter the maximum power of x: ");
    scanf("%d", &maxPow);
    for (i = maxPow; i >= 0; i--) {
        printf("Enter coefficient of degree %d: ", i);
        scanf("%d", &coeff);
        if (coeff != 0)
            insertTerm(&poly2, coeff, i);
    }

    printf("\nPolynomial 1: ");
    display(poly1);
    printf("Polynomial 2: ");
    display(poly2);

    // Addition
    sum = addPoly(poly1, poly2);
    printf("Sum: ");
    display(sum);

    return 0;
}

