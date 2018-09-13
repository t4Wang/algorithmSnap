/************************************************************************************
 *
 * ��������к����⣺
 * ��������A1,A2,...,AN(�����и���),
 * ���k=i->j Ak�����ֵ(Ϊ����������������������Ϊ����������������к�Ϊ0����
 * �磺
 * ����-2,11,-4,13,-5,-2ʱ����Ϊ20����A2��A4����
 *
 ************************************************************************************/
 /**
  * �������飬��ȡ�����Ӷ���ʽ�Ŀ���ֵ
  * ��i��ʼ����j������A[i]��A[k]ȡ�����п��ܵ��Ӷ���ʽ
  * (i->k��ȡ�������ж���ʽ,i->j�Ѿ�ȡ����һ��)
  *
  * ʱ�临�Ӷ�:N^3
  */
int MaxSubsequenceSum1(const int A[], int N) {
    int ThisSum, MaxSum, i, j, k;

    MaxSum = 0;
    for (i = 0; i < N; i++) {
        for (j = i; j < N; j++){
            ThisSum = 0;
            for (k = i; k <= j; k++) {
                ThisSum += A[k];
            }
            if (ThisSum > MaxSum) {
                MaxSum = ThisSum;
            }
        }
    }
}

/**
 * ����j�ڱ仯ʱʱ���еĶ���ʽ�͵�ֵ
 *
 * ʱ�临�Ӷȣ�N^2
 */
int MaxSubsequenceSum2(const int A[], int N) {
    int ThisSum, MaxSum, i, j;

    MaxSum = 0;
    for (i = 0; i < N; i++) {
        ThisSum = 0;
        for (j = i; j < N; j++) {
            ThisSum += A[j];
            if (ThisSum > MaxSum) {
                MaxSum = ThisSum;
            }
        }
    }
}

/**
 * ���η���
 * ���������п������������֣�
 * ��벿 �Ұ벿 ����м�ռ���������벿��
 *
 * ʱ�临�Ӷȣ�N*logN
 */
 int MaxSubsequenceSum3(const int A[], int startIndex, int endIndex) {
    // ��׼���
    if (startIndex == endIndex) {
        return A[startIndex];
    }

    int middleIndex = (startIndex + endIndex) / 2;

    // ��������������
    int maxLeft = MaxSubsequenceSum3(A, startIndex, middleIndex);
    // ���Ҳ����������
    int maxRight = MaxSubsequenceSum3(A, middleIndex, endIndex);
    // ���м����������
    //  ���м���ߵ����ֵ
    int i,currentLeftMiddle = 0, maxLeftMiddle = 0;
    for (i = 0; i <= middleIndex; i++) {
        currentLeftMiddle += A[i];
        if (currentLeftMiddle > maxLeftMiddle) {
            maxLeftMiddle = currentLeftMiddle;
        }
    }
    //  ���м���ߵ����ֵ
    int j, currentRightMiddle = 0, maxRightMiddle = 0;
    for (j = middleIndex; j < rightIndex; j++) {
        currentRightMiddle += A[j];
        if (currentRightMiddle > maxRightMiddle) {
            maxRightMiddle = currentRightMiddle;
        }
    }
    int maxMiddle = maxLeftMiddle + maxRightMiddle;
    // �����������ֵ
    if (maxMiddle > maxLeft) {
        if (maxMiddle > maxRight) return maxMiddle;
        else return maxLeft;
    } else if (maxLeft > maxRight) return maxLeft;
    else return maxRight;
 }

 /**
  * Ӱ���������͵�Ψһ�����Ǹ�����
  * �������ĳһ����Ϊ������һ����ʹ��������С��
  * �����С����Ĳ�������������ˣ��Ϳ����޳��������ʹ������
  *
  * ʱ�临�Ӷȣ�N
  */
int MaxSubsequenceSum4(const int A[], int N) {
    int i, currentSum = 0, maxSum = 0;

    for (i = 0; i < N; i++) {
        currentSum += A[i];
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
        if (currentSum < 0) {
            currentSum = 0;
        }
    }
    return maxSum;
}
