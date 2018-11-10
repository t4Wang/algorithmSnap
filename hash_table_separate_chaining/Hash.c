#include "Hash.h"
#include "Utils.h"
#include <stdlib.h>
#include <math.h>

const int MinTableSize = 10;

struct Node
{
    ElementType Element;
    Position Next;
};
typedef Position List;
struct HashTbl
{
    int TableSize;
    List *TheLists; // 哈希表存储的指向链表的数据数组
};

/**
 * 求下一个素数
 */
int NextPrime(int N)
{
    if (N % 2 == 0)
        ++N;
    int i;
    int notPrime = 0;
    while (1)
    {
        int k = floor(sqrt(N) + 0.5); // 避免重复算sqrt,通过四舍五入避免浮点误差，1.9999，m=sqrt(m),"0.9999将直接被截掉 只剩1"
        for (i = 2; i <= k; i++)
        {
            if (N % i == 0)
            {
                notPrime = 1;
                break;
            }
        }
        if (!notPrime)
            return N;
        N += 2;
    }
}

/**
 * Hash 函数
 */
int hash(ElementType Key, int TableSize)
{
    return Key;
}

HashTable InitializeTable(int TableSize)
{
    HashTable H;
    int i;

    if (TableSize < MinTableSize)
    {
        Error("Table size too small");
        return NULL;
    }

    /* Allocate table */
    H = malloc(sizeof(struct HashTbl));
    if (H == NULL)
        FatalError("Out of space!!!");

    /* 因为哈希表的大小最好是素数，所以初始化大小为大于TableSize的最小素数 */
    H->TableSize = NextPrime(TableSize);

    /* Allocate array of lists */
    /* 直接分配哈希表指向的链表指向的第一个节点所需空间 */
    H->TheLists = malloc(sizeof(List) * H->TableSize);
    if (H->TheLists == NULL)
        FatalError("Out of space!!!");

    /* Allocate list headers */
    for (i = 0; i < H->TableSize; i++)
    {
        H->TheLists[i] = malloc(sizeof(struct Node));
        if (H->TheLists[i] == NULL)
            FatalError("Out of space!!!");
        else
            H->TheLists[i]->Next = NULL;
    }

    return H;
}

void DestoryTable(HashTable H)
{
    if (H == NULL)
        return;
    int i;
    for (i = 0; i < H->TableSize; i++)
    {
        List list = H->TheLists[i];
        Position pos = list->Next;
        while (pos != NULL)
        {
            Position tmp = pos;
            pos = pos->Next;
            free(pos);
        }
        free(list);
    }
    free(H->TheLists);
    free(H);
}

Position Find(ElementType Key, HashTable H)
{
    List list = H->TheLists[hash(Key, H->TableSize)];
    Position pos = list->Next;
    while (pos != NULL && pos->Element != Key)
        pos = pos->Next;
    return pos;
}

void Insert(ElementType Key, HashTable H)
{
    Position pos = Find(Key, H);
    if (pos == NULL)
    {
        pos = malloc(sizeof(struct Node));
        if (pos == NULL)
        {
            FatalError("Out of space!!!");
            return;
        }
        pos->Element = Key;
        List list = H->TheLists[hash(Key, H->TableSize)];
        Position tmp = list->Next;
        list->Next = pos;
        pos->Next = tmp;
    }
}