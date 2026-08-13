

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check prime
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

// Function to calculate sum of prime numbers
int sumOfPrimes(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            sum += arr[i];
        }
    }
    return sum;
}

int main() {
    int n, *arr;

    printf("Enter size of the array: ");
    scanf("%d", &n);

    // Dynamic memory allocation
    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = sumOfPrimes(arr, n);

    printf("Sum = %d\n", sum);

    // Free allocated memory
    free(arr);

    return 0;
}




