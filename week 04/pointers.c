#include<stdio.h>
void main()
{
    int a=90;
    int *ap=&a;
    printf("%d\n",a);//prints 90
    printf("%d\n",ap);//prints address of a
    printf("%u\n",*ap);//prints the value of a ie 90
    for (1)
    {
        
    }

    printf("%u\n",&ap);//prints address of a with a difference of 4 since int is 4 bytes
}