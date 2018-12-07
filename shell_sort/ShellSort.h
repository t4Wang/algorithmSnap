/*************************************
 * 
 *   希尔排序
 * 
 * 希尔排序通过将比较的全部元素分为几个区域来提升插入排序的性能。
 * 这样可以让一个元素可以一次性地朝最终位置前进一大步。
 * 然后算法再取越来越小的步长进行排序，算法的最后一步就是普通的插入排序，
 * 但是到了这步，需排序的数据几乎是已排好的了（此时插入排序较快）。
 *
 * wiki: https://zh.wikipedia.org/wiki/希尔排序
 * 
 * 增量: h = N / 2 
 * 
 ************************************/
#ifndef SHELL_SORT_H
#define SHELL_SORT_H

typedef int ElementType;

void Shellsort(ElementType A[], int N);

#endif // SHELL_SORT_H
