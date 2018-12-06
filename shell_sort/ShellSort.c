#include "ShellSort.h"
#include "Utils.h"

void Shellsort(ElementType A[], int N) {
    int i, j, Increment;
    ElementType Tmp;
    // 缩少增量
    for (Increment = N / 2; Increment > 0; Increment /= 2)
        // 不同的增量序列
        for (i = Increment; i < N; i++) {
            Tmp = A[i];
            // 插入排序
            /* 从当前增量的值开始插入排序 
                即从增量序列第二个元素开始与前面的元素比较，
                此后这个增量序列已经比较过的部分是有序的 */ 
            for (j = i; j >= Increment; j -= Increment)
                if (Tmp < A[j - Increment])
                    A[j] = A[j - Increment];
                else
                    break;
            A[j] = Tmp;
        }
}
