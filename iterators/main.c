#include <stdio.h>

int func()
{
    int i = 1;
    int j = 2;
    return !(i != j);
}

int main()
{
    printf("%d",func());
}