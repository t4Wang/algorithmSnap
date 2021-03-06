/*************************************
 * 
 *   哈希表
 * 哈希表 开放定址法 线性寻址 实现
 * 
 ************************************/
#ifndef HASH_H
#define HASH_H

typedef int Position;
typedef const char* ElementType;  // 元素类型使用字符串
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestoryTable(HashTable H);
Position Find(ElementType Key, HashTable H);
// 使用再散列后必须将插入后的返回值赋给原来的哈希表
HashTable Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P); // 检索

extern const int MinTableSize;

#endif // HASH_H
