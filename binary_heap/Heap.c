#include "Heap.h"
#include "Utils.h"
#include <stdlib.h>
#include <math.h>

const int MinHeapSize = 10;
const ElementType MinData = 10;

struct HeapStruct
{
    int Capacity;
    int Size;
    ElementType *Elements; // 哈希表存储的指向链表的数据数组
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

PriorityQueue InitializeTable(int MaxElements)
{
    PriorityQueue H;
    int i;

    if (MaxElements < MinHeapSize)
        ;
    {
        Error("Priority queue size too small");
        return NULL;
    }

    H = malloc(sizeof(struct HeapStruct));
    if (H == NULL)
        FatalError("Out of space!!!");

    /* Allocate the array plus one extra for sentinel */
    /* [0]用来存放最小的值，这样插入时判断是否到达[1]可以节省一些时间 */
    H->Elements = malloc(sizeof(ElementType) * (MaxElements + 1));
    if (H->Elements == NULL)
        FatalError("Out of space!!!");

    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[0] = MinData;

    return H;
}

void Destory(PriorityQueue H)
{
    if (H == NULL)
        return;
    int i;
    free(H->Elements);
    free(H);
}

void MakeEmpty(PriorityQueue H)
{
    if (H == NULL)
        return;
    int i;
    for (i = 0; i < H->Size; i++)
    {
        H->Elements[i] = 0;
    }
}

ElementType FindMin(PriorityQueue H)
{
    ElementType ele;
    if (H->Elements[1] > H->Elements[0])
        ele = H->Elements[1];
    else
    {
        ele = H->Elements[0];
    }
    return ele;
}

/**
 * 二叉堆的特点：
 * 除根节点外所有节点的父亲在数组的索引是当前节点的1/2，
 * 左儿子的索引是当前节点的索引 * 2
 * 右儿子是左儿子索引 + 1
 */
void Insert(ElementType Key, PriorityQueue H)
{
    int curIndex;

    // 判断是否有空余
    if (IsFull(H))
    {
        Error("Priority queue is full");
        return;
    }

    /* [0]小于所有的值，所以不用加 && curIndex != 1判断是否到达首端 */
    for (curIndex = ++H->Size; H->Elements[curIndex / 2] > Key; curIndex /= 2)
        H->Elements[curIndex] = H->Elements[curIndex / 2];

    H->Elements[curIndex] = Key;
}

int IsFull(PriorityQueue H)
{
    if (H->Size >= H->Capacity)
        return 1;
    return 0;
}

/**
 * 删除最小的只需删除根节点
 * 将根节点两个子节点比较大小，将小的那个填上，随后继续向下填补，
 * 直到到达最后一层，将整个堆最后一个元素填上空
 */
ElementType DeleteMin(PriorityQueue H)
{
    ElementType minEle;
    if (IsEmpty(H))
    {
        Error("Priority queue is empty");
        return H->Elements[0];
    }
    minEle = H->Elements[1];

    int i = 1;
    // 循环 直到最后一层
    while (i * 2 < H->Size)
    {
        // 小的子节点往上填
        int child = H->Elements[i * 2] < H->Elements[i * 2 + 1] ? i * 2 : i * 2 + 1;
        H->Elements[i] = H->Elements[child];
        i = child;
    }
    H->Elements[i] = H->Elements[H->Size];
    H->Size -= 1;
    return minEle;
}

int IsEmpty(PriorityQueue H)
{
    if (H == NULL || H->Size < 1)
        return 1;
    return 0;
}