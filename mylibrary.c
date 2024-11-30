#include<stdio.h>
#include "mylibrary.h"

MYLIBRARY_API int factorial(int num)
{
    int fac=1;
    for (int i = 1; i <= num; i++)
    {
        fac*=i;
    }
    return fac;
}