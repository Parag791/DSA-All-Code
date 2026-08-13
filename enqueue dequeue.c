#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isFull() {
    return rear == SIZE - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int value) {
    if (isFull())
        printf("Queue is Full!\n");
    else {
        if (front == -1)
            front = 0;
        queue[++rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

void dequeue() {
    if (isEmpty())
        printf("Queue is Empty!\n");
    else
        printf("Dequeued: %d\n", queue[front++]);
}

void traverse() {
    if (isEmpty())
        printf("Queue is Empty!\n");
    else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n2. Dequeue\n3. IsEmpty\n4. IsFull\n5. Traverse\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter element: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            if (isEmpty())
                printf("Queue is Empty\n");
            else
                printf("Queue is not Empty\n");
            break;
        case 4:
            if (isFull())
                printf("Queue is Full\n");
            else
                printf("Queue is not Full\n");
            break;
        case 5:
            traverse();
            break;
        case 6:
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}
