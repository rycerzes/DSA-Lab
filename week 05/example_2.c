#include<stdio.h>
int main()
{
    int n, a[n][n];
    printf("Enter size of the square matrix:");
    scanf("%d",&n);
    printf("Enter the elements of the matrix");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    return 0;
}