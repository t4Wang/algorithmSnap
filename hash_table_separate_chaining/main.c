#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"

int main()
{
    printf("Hello world!\n");

    HashTable h = InitializeTable(100);

    Insert(11, h);

    Position p = Find(11, h);

    DestoryTable(h);
    
    return 0;
}