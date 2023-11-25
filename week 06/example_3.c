#include<stdio.h>
int nonzero(int a[n][n])
{
	int count=0;
	for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if (arr[i][j]!=0);
            count=count+1;
        }
    }
    return count;
}
int main()
{
    int n, a[n][n], choice, c;
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
    printf("1.Number of non zero elements in matrix\n");
    printf("2.Display upper triangle\n");
    printf("Enter choice:");
    scanf("%d", &choice);
    switch(choice)
    {
    	case 1: c=nonzero(n,a[n][n]);
    	        printf("Number of non zero elements is %d", c);
    	        break;
	}

    return 0;
}