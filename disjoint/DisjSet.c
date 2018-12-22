#include "DisjSet.h"
#include "Utils.h"
#include <stdlib.h>
#include <math.h>

// static const int NumSets = 13;

// 初始化
void Initialize(DisjSet S)
{
    int i;
    for (i = 0; i <= NumSets; i++)
        S[i] = -1;
}
// 简单求并
void simpleUnion(DisjSet S, SetType Root1, SetType Root2)
{
    S[Root2] = Root1;
}
// 灵巧求并
// 按大小求并（union-by-size)
void unionBySize(DisjSet S, SetType Root1, SetType Root2)
{
    if (S[Root1] < S[Root2])
        S[Root2] = Root1;
    else
        S[Root1] = Root2;
}
// 按高度求并（union-by-height)
void unionByHeight(DisjSet S, SetType Root1, SetType Root2)
{
    if (S[Root2] < S[Root1])
        S[Root1] = Root2;
    else
    {
        if (S[Root1] == S[Root2])
            S[Root1]--;
        S[Root2] = Root1;
    }
}
// 合并
void SetUnion(DisjSet S, SetType Root1, SetType Root2)
{
    // simpleUnion(S, Root1, Root2);
    // unionBySize(S, Root1, Root2);
    unionByHeight(S, Root1, Root2);
}
// 简单查找
SetType SimpleFind(DisjSet S, ElementType X)
{
    if (S[X] <= 0)
        return X;
    return SimpleFind(S, S[X]);
}
// 路径压缩查找
// 从X到根的路径上的每一个节点都使它的父节点变成根
SetType PassCompressionFind(DisjSet S, ElementType X) {
    if (S[X] <= 0)
        return X;
    S[X] = PassCompressionFind(S, S[X]);
    return S[X];
}
// 查找，传入要查找的索引 返回集合的根索引
SetType Find(DisjSet S, ElementType X)
{
    // SimpleFind(S, X);
    return PassCompressionFind(S, X);
}
