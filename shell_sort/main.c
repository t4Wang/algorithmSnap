#include <stdio.h>
#include <stdlib.h>
#include "ShellSort.h"

int main()
{
    ElementType A[] = {81, 94, 11, 96, 12, 35, 17, 95, 28, 58, 41, 75, 15};
    int i;
    const int SIZE = 13;

    for (i = 0; i < SIZE; i++)
        printf("%d ", A[i]);
    printf("\n");

    Shellsort(A, SIZE);

    for (i = 0; i < SIZE; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}