/**
 * Ͱ���� ռ���ٿռ��
 * �Ҷ������У����� λ�� * ���� ��(n)
 */
 struct Node;
 typedef struct Node* List;
 typedef struct Node* Position;

int Bucket(const int A[], int Digit, int N) {
    int Decimal = 10;
    int i;
    Node B[Decimal];

    for (i = 1; i <= Digit; i++) {
        // ����һ������ǰλ�����������������
        for (j = 0; j < N; j++) {
            //��ȡ��ȷ��Ͱ�ı��
            int d = A[j] % (Decimal ^ i);
            // ��ȡͰ��ĩ�˽ڵ�
            Node n = last(B[d - 1]);
            // ��������Ľڵ���ӵ�ĩ��
            n -> next = initial(A[j]);
        }
        // ���Ѿ������ź���������ٲ������
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
            // �ͷ�����Ԫ��
            release(curE);
            curE = temp;
        }
    }
}

typedef struct {
    int data;
    Position next;
} Node;
