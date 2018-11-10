/**
 * 桶排序 占用少空间版
 * 右对齐排列，遍历 位数 * 进制 次(n)
 */
 struct Node;
 typedef struct Node* List;
 typedef struct Node* Position;

int Bucket(const int A[], int Digit, int N) {
    int Decimal = 10;
    int i;
    Node B[Decimal];

    for (i = 1; i <= Digit; i++) {
        // 生成一个按当前位初步排序的链表数组
        for (j = 0; j < N; j++) {
            //获取正确的桶的编号
            int d = A[j] % (Decimal ^ i);
            // 获取桶的末端节点
            Node n = last(B[d - 1]);
            // 将待排序的节点添加到末端
            n -> next = initial(A[j]);
        }
        // 将已经初步排好序的链表再插回数组
        int curD = 0;
        Node curE = B[curD];
        for (j = 0; j < N; j++) {
            A[j] = curE.data;
            Node temp;
            if (curE -> next != null) {
                temp = curE->next;
            } else {
                curD++;
                temp = B[curD];
            }
            // 释放链表元素
            release(curE);
            curE = temp;
        }
    }
}

typedef struct {
    int data;
    Position next;
} Node;
