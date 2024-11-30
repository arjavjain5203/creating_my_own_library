#include<stdio.h>
#include "mylibrary.h"


int main()
{
    int x;
    printf("enter the number to find its factorial ");
    scanf("%d",&x);
    int f=factorial(x);
    printf("%d",f);
    return 0;
}