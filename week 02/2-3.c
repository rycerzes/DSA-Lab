#include <stdio.h>
void tuple(int m[][100], int rows, int cols)
{
    int tuple3[100][3];
    int c = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (m[i][j] != 0)
            {
                tuple3[c][0] = i;
                tuple3[c][1] = j;
                tuple3[c][2] = m[i][j];
                c++;
            }
        }
    }
    
    printf("3-Tuple:\n");
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < c; i++)
    {
        printf("%d\t%d\t%d\n", tuple3[i][0], tuple3[i][1], tuple3[i][2]);
    }
}
int main()
{
    int matrix[100][100];
    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter the elements:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    tuple(matrix, rows, cols);
    return 0;
}
/*
#include <stdio.h>
#include <stdlib.h>

void tuple()
{
}

int main()
{
    int m, n, j, i, c = 0;
    printf("enter no of rows:\n");
    scanf("%d", &m);
    printf("enter no of columns:\n");
    scanf("%d", &n);
    printf("enter elements:\n");
    int a[m][n];

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] != 0)
                c++;
        }
    }

    if (c > ((m * n) / 2))
        return 1;

    int tuple3[c][3];
    c=0;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                tuple3[c][0]=i;
                tuple3[c][1]=j;
                tuple3[c][2]=a[i][j];
                c++;
            }
        }
    }
    
    printf("3-tuple format:\n");
    printf("row\tcolumn\tvalue\n");
    
    for(i=0;i<=c;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",tuple3[i][j]);
        }
        printf("\n");
    }
}

*/