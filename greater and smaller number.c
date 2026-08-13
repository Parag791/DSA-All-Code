#include<stdio.h>
void compare(int *a,int *b)
{
if( *a > *b)
printf("%d is greater than %d\n", *a,*b);
else if( *a < *b)
printf("%d is smaller than %d\n", *a,*b);
else
printf("Both numbers are same\n");
}
int main()
{
int x,y;
printf("Enter two numbers");
printf("%d%d",x,y);
compare(&x,&y);
return 0;
}
