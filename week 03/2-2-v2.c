#include <stdio.h>

void read(int *a, int n) {
    printf("Enter %d x %d elements:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", a + i * n + j);
        }
    }
}

void display(int *a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", *(a + i * n + j));
        }
        printf("\n");
    }
}

int main() {
    int n=3;
    
    int a[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j]=0;
        }
    }
    display(&a[0][0], n);
        
    read(&a[0][0], n);

    display(&a[0][0], n);

    return 0;
}
