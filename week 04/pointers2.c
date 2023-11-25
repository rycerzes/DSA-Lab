# include <stdio.h>
void fun(int *ptr)//how to declare a function with pointers
{
    /*
    the address of y will get passed to the function fun when it's called
    the variable '*ptr' will hold the address of y
    when you use print statement, it will print the value of y
    note: *ptr is for calling the value and &ptr will give address as an output
    */
    printf("%u\n",*ptr);//will print value of y ie 20
}
 
int main()
{
  int y = 20;
  fun(&y);//how to pass values to a function using pointer
  printf("%d\n", y);
 
  return 0;
}
