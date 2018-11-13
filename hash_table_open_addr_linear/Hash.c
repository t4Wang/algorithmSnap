#include "Hash.h"
#include "Utils.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>

const int MinTableSize = 10;

typedef int KindOfEntry;
const KindOfEntry Legitimate = 1;
const KindOfEntry Empty = 2;
const KindOfEntry Deleted = 3;

struct HashEntry
{
    ElementType Element;
    KindOfEntry Info;
};
typedef struct HashEntry Cell;

struct HashTbl
{
    int TableSize;
    Cell *TheLists; // 哈希表存储的指向链表的数据数组
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
    unsigned int hashVal = 0;

    while (*Key != '\0')
        hashVal = (hashVal << 5) + *Key++;
    return hashVal % TableSize;
}

/**
 * 再散列
 */
HashTable ReHash(HashTable oldTable) {
    HashTable newTable = InitializeTable(oldTable->TableSize * 2);
    int i;
    for (i = 0; i < oldTable->TableSize; i++) {
        if (oldTable->TheLists[i].Info == Legitimate)
            Insert(oldTable->TheLists[i].Element, newTable);
    }
    free(oldTable);
    return newTable;
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
    H->TheLists = malloc(sizeof(Cell) * H->TableSize);
    if (H->TheLists == NULL)
        FatalError("Out of space!!!");

    for (i = 0; i < H->TableSize; i++)
    {
        H->TheLists[i].Info = Empty;
        H->TheLists[i].Element = NULL;
    }
    return H;
}

void DestoryTable(HashTable H)
{
    if (H == NULL)
        return;
    int i;
    free(H->TheLists);
    free(H);
}

Position Find(ElementType Key, HashTable H)
{
    int pos = hash(Key, H->TableSize);

    // char*
    int collisionNum = 0;
    while (H->TheLists[pos].Info != Empty && strcmp(H->TheLists[pos].Element, Key) == 0)
    {
        pos += 2 * ++collisionNum - 1;
        if (pos >= H->TableSize)
            pos -= collisionNum;
    }
    return pos;
}

HashTable Insert(ElementType Key, HashTable H)
{
    Position pos = Find(Key, H);
    if (H->TheLists[pos].Info == Empty)
    {
        H->TheLists[pos].Element = Key;
        H->TheLists[pos].Info = Legitimate;
    } else {
        H = ReHash(H);
        Insert(Key, H);
    }
    return H;
}