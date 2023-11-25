//wap to create aay of n elements with dynamic mem alloc and sum of all prime nos. using function
#include <stdio.h>
#include <stdlib.h>
int prime(int num) 
{
    if (num <= 1)
        return 0;
    for (int i = 2; i * i <= num; i++) 
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}
int main() 
{
    int n;
    printf("number of elements: ");
    scanf("%d", &n);
    if (n <= 0) 
    {
        printf("error!\n");
        return 1;
    }
    int *a = (int *)malloc(n * sizeof(int));
    if (a == NULL) 
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) 
    {
        if (prime(a[i])) {
            sum += a[i];
        }
    }
    printf("sum of prime elements: %d\n", sum);
    free(a);
    return 0;
}