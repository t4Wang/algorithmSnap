// 哈希表
#ifndef HASH_H
#define HASH_H

typedef int ElementType;
struct Node;
struct HashTbl;
typedef struct Node *Position;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestoryTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P); // 检索

extern const int MinTableSize;

#endif // HASH_H
