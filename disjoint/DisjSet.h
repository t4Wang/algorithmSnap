/*************************************
 * 
 *   不相交集 Disjoint Set
 * 
 ************************************/
#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#define NumSets 13

// 集合元素的类型
typedef int ElementType;
// 存集合索引的类型
typedef int SetType;
// NumSets + 1大小的数组类型
typedef int DisjSet[NumSets + 1];

// 初始化
void Initialize(DisjSet S);
// 合并
void SetUnion(DisjSet S, SetType Root1, SetType Root2);
// 查找，返回集合名字
SetType Find(DisjSet S, ElementType X);

#endif // DISJOINT_SET_H
