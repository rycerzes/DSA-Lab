#include <stdio.h>
#include <stdlib.h>

void tuple(int **a, int m, int n, int c)
{
    int i, j;
    int tuple3[c][3];

    c = 0;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] > 0)
            {
                tuple3[c][0] = i;
                tuple3[c][1] = j;
                tuple3[c][2] = a[i][j];
                c++;
            }
        }
    }

    printf("3-tuple format:\n");
    printf("row\tcolumn\tvalue\n");

    for (i = 0; i < c; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", tuple3[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int m, n, j, i, c = 0;
    printf("enter no of rows:\n");
    scanf("%d", &m);
    printf("enter no of columns:\n");
    scanf("%d", &n);

    int **a = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int));
    }

    printf("enter elements:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] != 0)
            {
                c++;
            }
        }
    }

    if (c > ((m * n) / 2))
    {
        return 1;
    }

    tuple(a, m, n, c);

    for (i = 0; i < m; i++)
    {
        free(a[i]);
    }
    free(a);

    return 0;
}
