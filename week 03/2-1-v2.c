/*
2.1 WAP to create a 1-D array of n elements and perform the following menu based operations using function.
# only use malloc() and functions
a. insert a given element at specific position.
b. delete an element from a specific position of the array.
c. linear search to search an element
d. traversal of the array 
*/

#include <stdio.h>
#include <stdlib.h>

void insert(int **a1, int *n, int pos, int ins)
{
    (*n)++;
    int *a = (int *)realloc(*a1, (*n) * sizeof(int));
    if (a == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    *a1 = a;
    for (int i = *n - 1; i > pos; i--)
    {
        (*a1)[i] = (*a1)[i - 1];
    }
    (*a1)[pos] = ins;
    for (int i = 0; i < *n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void delete(int **a1, int *n, int pos)
{
    (*n)--;
    int *a = (int *)realloc(*a1, (*n) * sizeof(int));
    *a1 = a;
    for (int i = pos - 1; i < *n; i++)
        a[i] = a[i + 1];
    for (int i = 0; i < *n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void search(int **a1, int *n, int ins)
{
    int i, c = 0;
    int *a = (int *)realloc(*a1, (*n) * sizeof(int));
    *a1 = a;
    for (i = 0; i < *n; i++)
    {
        if (a[i] == ins)
        {
            c++;
            break;
        }
    }
    if (c > 0)
        printf("element found at position %d\n", i + 1);
    else
        printf("element not found\n");
}

void traversal(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int n;
    int pos=0,ins=0;
    // int pos = 2;
    // int ins = 2;

    printf("Enter size of array\n");
    scanf("%d",&n);

    int *a = (int *)malloc(n * sizeof(int));

    if (a == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("enter elements of array:\n");
    for (int i = 0; i < n; i++)
    scanf("%d",&(*(a+i)));

    // for (int i = 0; i < n; i++)
    //     printf("%d ", a[i]);

    printf("\n");

    int choice = 0;
    printf("1. insert element\n2. delete element\n3. linear search for element\n4. traversal of array\n5. exit\n");
    printf("select an option\n");
    scanf("%d", &choice);

    switch (choice)
    {

    case 1:
        printf("enter element to be insert\n");
        scanf("%d",&ins);  
        printf("enter position of new array\n");
        scanf("%d",&pos);
        insert(&a, &n, pos, ins);
        break;

    case 2:
        printf("enter position to be deleted\n");
        scanf("%d",&pos);
        delete(&a,&n,pos);
        break;

    case 3:
        printf("enter element to be searched\n");
        scanf("%d",&ins);
        search(&a,&n,ins);
        break;

    case 4:
        traversal(a,n);
        break;

    case 5:
        printf("exited\n");
        break;

    default:
    {
        printf("exited since wrong choice\n");
        break;
    }
    }
    free(a);
    return 0;
}