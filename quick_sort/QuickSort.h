/*************************************
 * 
 *   快速排序
 * 
 * 不断选出一个枢纽点，将剩下的元素按大小分列它的两边，再继续排序它两边的数列，最终达到有序
 * 
 ************************************/
#ifndef QUICKSORT_H
#define QUICKSORT_H

typedef int ElementType;
void QuickSort(ElementType A[], int N);

#endif // QUICKSORT_H
