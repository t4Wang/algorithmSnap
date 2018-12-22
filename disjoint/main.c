#include <stdio.h>
#include <stdlib.h>
#include "DisjSet.h"

int main()
{
    DisjSet S;
    Initialize(S);
    int i;
    for (i = 1; i <= NumSets; i += 2) {
        SetUnion(S, i, i + 1);
    }
    for (i = 1; i <= NumSets; i += 4) {
        SetUnion(S, i, i + 2);
    }
    for (i = 1; i <= NumSets; i += 8) {
        SetUnion(S, i, i + 4);
    }
    Find(S, 8);
    return 0;
}