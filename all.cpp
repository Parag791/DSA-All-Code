//#include<stdio.h>

int main() {

    int a[] = {3, 1, 4, 1, 5};
    int n = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);

    printf("\n");

    return 0;
}
