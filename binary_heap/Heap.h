/*************************************
 * 
 *   优先队列（堆）
 * 堆 二叉堆 实现
 * 
 ************************************/
#ifndef HEAP_H
#define HEAP_H

typedef int ElementType;
struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;

PriorityQueue InitializeTable(int TableSize);
void Destory(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType Key, PriorityQueue H);
ElementType FindMin(PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H); // 检索

extern const int MinHeapSize;

#endif // HEAP_H
