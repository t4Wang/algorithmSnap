#include <stdio.h>
#include <stdlib.h>
#include "MergeSort.h"

int main()
{
    const int N = 13;
    ElementType A[] = {81, 94, 11, 96, 12, 35, 17, 95, 28, 58, 41, 75, 15};

    MergeSort(A, N);

    return 0;
}