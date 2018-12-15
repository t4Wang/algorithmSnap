#include "QuickSort.h"
#include "Utils.h"
#include <stdlib.h>
#include <math.h>

// 进行插入排序的界值
const int Cutoff = 3;

void QuickSort(ElementType A[], int N);
void QSort(ElementType A[], int Left, int Right);
void Merge(ElementType A[], ElementType TmpArray[], int Lpos, int Rpos, int RightEnd);
void Swap(ElementType *a1, ElementType *a2);
void InsertionSort(ElementType A[], int N);

/**
 * 快速排序启动程序
 */
void QuickSort(ElementType A[], int N)
{
    QSort(A, 0, N - 1);
}

void QSort(ElementType A[], int Left, int Right)
{
    int lpos, rpos;

    if (Left + Cutoff < Right)
    {
        // 选取枢纽元
        int Center = (Left + Right) / 2;
        if (A[Left] > A[Center])
            Swap(&A[Left], &A[Center]);
        if (A[Left] > A[Right])
            Swap(&A[Left], &A[Right]);
        if (A[Center] > A[Right])
            Swap(&A[Center], &A[Right]);
        // 中间值的放在最后
        Swap(&A[Center], &A[Right - 1]);
        Center = Right - 1;
        // 划分
        lpos = Left;
        rpos = Right - 1;
        for (;;)
        {
            // 由于两边有值作为界限存在，while语句一定不会越界
            // 先++--，这样如果开始时lpos=rpos=center也不会陷入死循环
            while (A[++lpos] < A[Center]);
            while (A[--rpos] > A[Center]);
            if (lpos < rpos)
                Swap(&A[lpos], &A[rpos]);
            else
                break;
        }
        Swap(&A[lpos], &A[Center]);

        // 继续对子序列进行划分
        QSort(A, Left, lpos - 1);
        QSort(A, lpos + 1, Right);
    }
    else
    {
        // 插入排序
        InsertionSort(A + Left, Right - Left + 1);
    }
}

/**
 * 合并数组
 * 将两个排好序的数组插入新数组
 */
void Merge(ElementType A[], ElementType TmpArray[], int Lpos, int Rpos, int RightEnd)
{
    int i, LeftEnd, NumElements, TmpPos;

    // initial
    LeftEnd = Rpos - 1;
    TmpPos = Lpos;                     // 排序数组的位置 初始化为插入已排序数组的起始位置
    NumElements = RightEnd - Lpos + 1; // 元素个数

    /* main loop */
    while (Lpos <= LeftEnd && Rpos <= RightEnd)
        if (A[Lpos] <= A[Rpos])
            TmpArray[TmpPos++] = A[Lpos++];
        else
            TmpArray[TmpPos++] = A[Rpos++];
    while (Lpos <= LeftEnd)
        TmpArray[TmpPos++] = A[Lpos++];
    while (Rpos <= RightEnd)
        TmpArray[TmpPos++] = A[Rpos++];

    /* Copy TmpArray back */
    for (i = 0; i < NumElements; i++, RightEnd--)
        A[RightEnd] = TmpArray[RightEnd];
}

/**
 * 交换
 */
void Swap(ElementType *a1, ElementType *a2)
{
    ElementType tmp = *a1;
    *a1 = *a2;
    *a2 = tmp;
}
/**
 * 插入排序 
 */
void InsertionSort(ElementType A[], int N)
{
    int i, j;
    ElementType tmp;

    for (i = 1; i < N; i++)
    {
        // j 遍历的是已排序数列，i代表的值择机插入
        tmp = A[i];
        for (j = i; j > 0 && A[j - 1] > tmp; j--)
            A[j] = A[j - 1];
        A[j] = tmp;
    }
}