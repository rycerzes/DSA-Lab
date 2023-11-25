//wap to program to read 2 numbers and compare the numbers using function call by address
#include <stdio.h>
void compare(int *n1, int *n2)
{
    if(*n1>*n2)
    printf("first one is larger");
    else if(*n2>*n1)
    printf("second one is larger");
    else
    printf("equal");    
}
int main()
{
    int n1,n2;
    printf("enter a no\n");
    scanf("%d",&n1);
    printf("enter a no\n");
    scanf("%d",&n2);
    compare(&n1,&n2);
    return 0;
}