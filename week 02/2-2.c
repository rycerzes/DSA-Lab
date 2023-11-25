#include <stdio.h>
void read(int a[][10], int n)
{
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

int nonzero(int a[][10], int n)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                c++;
            }
        }
    }
    return c;
}

void uppertriangle(int a[][10], int n)
{
    printf("Upper Triangular array:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j >= i)
            {
                printf("%d ", a[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void diagonals(int a[][10], int n)
{
    printf("Elements above and below the main diagonal:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                printf("%d ", a[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}
int main()
{
    int a[10][10];
    int n;
    printf("Enter the size of the square array: ");
    scanf("%d", &n);
    read(a, n);
    printf("Number of non-zero elements: %d\n", nonzero(a, n));
    uppertriangle(a, n);
    diagonals(a, n);

    return 0;
}
