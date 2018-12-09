#include "MergeSort.h"
#include "Utils.h"
#include <stdlib.h>
#include <math.h>

/**
 * 合并数组
 * 将两个排好序的数组插入新数组
 */
void Merge(ElementType A[], ElementType TmpArray[], int Lpos, int Rpos, int RightEnd) {
    int i, LeftEnd, NumElements, TmpPos;
    
    // initial
    LeftEnd = Rpos - 1;
    TmpPos = Lpos;                      // 排序数组的位置 初始化为插入已排序数组的起始位置
    NumElements = RightEnd - Lpos + 1;  // 元素个数

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
    for ( i = 0; i < NumElements; i++, RightEnd--)
        A[RightEnd] = TmpArray[RightEnd];
}

void MSort(ElementType A[], ElementType TmpArray[], int Left, int Right) {
    int Center;

    if (Left < Right) {
        Center = (Left + Right) / 2;
        MSort(A, TmpArray, Left, Center);
        MSort(A, TmpArray, Center + 1, Right);
        Merge(A, TmpArray, Left, Center + 1, Right);
    }
}

/**
 * 归并排序递归实现的启动函数
 * 将一个无序数组传入MSort进行排序 
 */
void MergeSort(ElementType A[], int N) {
    ElementType *TmpArray;

    TmpArray = malloc(N * sizeof(ElementType));
    if (TmpArray != NULL){
        MSort(A, TmpArray, 0, N - 1);
        free(TmpArray);
    } else
        FatalError("No space for tmp array!!!");
}