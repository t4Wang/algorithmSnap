#include "HeapSort.h"
#include "Utils.h"
#include <stdlib.h>
#include <math.h>

// 左孩子的数组索引
// 索引从0开始，所以左孩子是父亲的索引 * 2 + 1
#define LeftChild(i)(2 * (i) + 1)

void Swap(ElementType* a1, ElementType* a2) {
    ElementType tmp = *a1;
    a1 = a2;
    *a2 = tmp;
}

/**
 * 将最大的元素上移到i的位置
 */
void PercDown(ElementType A[], int i, int N) {
    int Child;
    ElementType Tmp;

    // 将最大的元素上移到i的位置
    for (Tmp = A[i]; LeftChild(i) < N; i = Child) {
        Child = LeftChild(i);
        // 右儿子的值比左儿子的值大，切换到右儿子
        if (Child != N - 1 && A[Child + 1] > A[Child])
            Child++;
        if (Tmp < A[Child])
            A[i] = A[Child];
        else
            // 为什么两个儿子都比父亲小就不用继续比较儿子的儿子了？
            // 因为这个函数的调用是按逆推的顺序调用的，从最底层往上排，
            // 两个儿子都比父亲小，要么两个儿子就是底层，如果不是底层的话就已经有父亲比儿子大这个顺序了
            break;
    }
    // i实际值是之前的Child
    A[i] = Tmp;
}

/**
 * 将一个无序数组首先构建堆，然后删除最大值达到排序的目的 
 */
void Heapsort(ElementType A[], int N) {
    int i;

    // 构建堆
    // 从左孩子开始构建，所以父亲的值是N / 2 - 1
    for (i = N / 2 - 1; i >= 0; i--)    /* BuildHeap */
        PercDown(A, i, N);
    // 删除最大元素
    // 最大的元素排在最后面，逆序遍历完一遍的时候，整个数组就是有序的了
    for (i = N - 1; i > 0; i--) {   /* DeleteMax */
        Swap(&A[0], &A[i]);
        PercDown(A, 0, i);
    }
}