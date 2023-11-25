/*wap to create a 1-d array and perform the following menu based ops
a. insert element
b. delete element
c. linear search for element
d. traversal of array
e. exit
*/
#include <stdio.h>
void main()
{
    int n, i, ins, pos;
    printf("enter n\n");
    scanf("%d", &n);
    int a[n];
    printf("enter elements\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int ui = 0;
    printf("1. insert element\n2. delete element\n3. linear search for element\n4. traversal of array\n5. exit\n");
    printf("select an option\n");
    scanf("%d", &ui);
    switch (ui)
    {

    case 1:
    {
        printf("enter element to be insert\n");
        scanf("%d", &ins);
        printf("enter position of new array\n");
        scanf("%d", &pos);
        n++;

        for (i = n - 1; i >= pos; i--)
            a[i] = a[i - 1];
        a[pos - 1] = ins;
        printf("Array elements after insertion\n");
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
        break;
    }

    case 2:
    {
        printf("enter position at which element should be deleted");
        scanf(" %d", &pos);

        for (i = pos - 1; i < n - 1; i++)
        {
            a[i] = a[i + 1];
        }
        printf(" \n The resultant array is: \n");
        for (i = 0; i < n - 1; i++)
            printf(" %d \n", a[i]);

        break;
    }

    case 3:
    {
        printf("Enter the element to search ie. key element: ");
        scanf("%d", &ins);
        for (i = 0; i < n; i++)
            if (a[i] == ins)
                break;
        if (i < n)
            printf("Key element found");
        else
            printf("Key element not found");

        break;
    }

    case 4:
    {
        for (i = 0; i < n; i++)
        {
            printf("%d\n", a[i]);
        }
        break;
    }

    case 5:
    {
        printf("exited\n");
        break;
    }

    default:
    {
        printf("wrong choice\n");
        break;
    }
    }
}