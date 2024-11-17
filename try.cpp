#include <stdio.h>

int m = 25;

int main()
{
    int *q = &m;
    int ***f(int **);
    int ***p;
    p = f(&q);

    printf("%d", ***p);
    return 0;
}

int ***f(int **q)
{
    **q *= **q;
    m += 1;
    return (&q);
}