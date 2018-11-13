#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

int main()
{
    printf("Hello world!\n");

    PriorityQueue h = InitializeTable(100);

    Insert(11, h);
    Insert(21, h);
    Insert(1, h);
    Insert(10, h);
    Insert(16, h);

    DeleteMin(h);

    int p = FindMin(h);

    Destory(h);

    return 0;
}