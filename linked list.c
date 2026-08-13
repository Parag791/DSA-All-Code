#include <stdio.h>
#include <stdlib.h>

struct Node {
    int row, col, value;
    struct Node *next;
};

struct Node* createNode(int row, int col, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node *head) {
    struct Node *temp = head;
    printf("Sparse matrix in 3-tuple format\n");
    while (temp != NULL) {
        printf("%d\t%d\t%d\n", temp->row, temp->col, temp->value);
        temp = temp->next;
    }
}

int main() {
    int m, n, i, j, value;
    struct Node *head = NULL, *temp = NULL, *newNode;

    printf("Enter size of the sparse matrix: ");
    scanf("%d %d", &m, &n);

    printf("Enter elements of sparse matrix: ");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &value);
            if (value != 0) {  // store only non-zero elements
                newNode = createNode(i, j, value);
                if (head == NULL)
                    head = newNode;
                else
                    temp->next = newNode;
                temp = newNode;
            }
        }
    }

    printf("\n%d\t%d\t%d\n", m, n, 0);  // first line header (optional)
    display(head);

    return 0;
}





