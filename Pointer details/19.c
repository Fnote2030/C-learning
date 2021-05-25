#include<stdio.h>

int main()
{
    char *a[10][64] = {{"abc","bcd"},{"cdf","123"},{"52341","gadsk"}};
    printf("%s", a[1][1]);
    return 0;
}