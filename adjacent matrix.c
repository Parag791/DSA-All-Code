#include <stdio.h>

// Function to count nonzero elements
int countNonZero(int a[10][10], int n) {
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != 0)
                count++;
    return count;
}

// Function to display upper triangular matrix (excluding diagonal)
void displayUpperTriangular(int a[10][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > i) // strictly above main diagonal
                printf("%d ", a[i][j]);
            else
                printf("  "); // spaces for formatting
        }
        printf("\n");
    }
}

// Function to display elements just above and below main diagonal
void displayAdjacentDiagonal(int a[10][10], int n) {
    printf("Elements just above and below main diagonal:\n");
    for (int i = 0; i < n; i++) {
        if (i < n - 1)  // Above diagonal
            printf("%d ", a[i][i + 1]);
        if (i > 0)      // Below diagonal
            printf("%d ", a[i][i - 1]);
    }
    printf("\n");
}

int main() {
    int n, a[10][10];
    printf("Enter size of the square matrix: ");
    scanf("%d", &n);

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Nonzero elements : %d\n", countNonZero(a, n));
    printf("Upper triangular matrix:\n");
    displayUpperTriangular(a, n);
    displayAdjacentDiagonal(a, n);

    return 0;
}

