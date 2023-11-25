#include <stdio.h>
#include <stdlib.h>
void prime(int a[], int n)
{
    int i, j, sum = 0, c = 0;
    for (i = 0; i < n; i++)
    {
        c = 0;
        for (j = 2; j < a[i]; j++)
        {
            if (a[i] % j == 0)
            {
                c = 1;
                break;
            }
        }
        if (c == 0)
        {
            sum = sum + a[i];
        }
    }
    printf("sum = %d\n", sum);
}
int main()
{
    int n;
    printf("Enter size of array\n");
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));

    if (a == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("enter elements of array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &(*(a + i)));

    prime(a, n);

    free(a);
    return 0;
}