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
