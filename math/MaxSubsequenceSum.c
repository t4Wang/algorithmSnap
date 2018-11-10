/************************************************************************************
 *
 * 最大子序列和问题：
 * 给定整数A1,A2,...,AN(可能有负数),
 * 求∑k=i->j Ak的最大值(为方便起见，如果所有整数均为负数，则最大子序列和为0）。
 * 如：
 * 输入-2,11,-4,13,-5,-2时，答案为20（从A2到A4）。
 *
 ************************************************************************************/
 /**
  * 遍历数组，获取所有子多项式的可能值
  * 从i开始，到j结束，A[i]到A[k]取到所有可能的子多项式
  * (i->k所取到的所有多项式,i->j已经取到过一遍)
  *
  * 时间复杂度:N^3
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
 * 计算j在变化时时所有的多项式和的值
 *
 * 时间复杂度：N^2
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
 * 分治法：
 * 最大的子序列可能在三处出现，
 * 左半部 右半部 横跨中间占据左右两半部分
 *
 * 时间复杂度：N*logN
 */
 int MaxSubsequenceSum3(const int A[], int startIndex, int endIndex) {
    // 基准情况
    if (startIndex == endIndex) {
        return A[startIndex];
    }

    int middleIndex = (startIndex + endIndex) / 2;

    // 求左侧最大子序列
    int maxLeft = MaxSubsequenceSum3(A, startIndex, middleIndex);
    // 求右侧最大子序列
    int maxRight = MaxSubsequenceSum3(A, middleIndex, endIndex);
    // 求中间最大子序列
    //  求中间左边的最大值
    int i,currentLeftMiddle = 0, maxLeftMiddle = 0;
    for (i = 0; i <= middleIndex; i++) {
        currentLeftMiddle += A[i];
        if (currentLeftMiddle > maxLeftMiddle) {
            maxLeftMiddle = currentLeftMiddle;
        }
    }
    //  求中间左边的最大值
    int j, currentRightMiddle = 0, maxRightMiddle = 0;
    for (j = middleIndex; j < rightIndex; j++) {
        currentRightMiddle += A[j];
        if (currentRightMiddle > maxRightMiddle) {
            maxRightMiddle = currentRightMiddle;
        }
    }
    int maxMiddle = maxLeftMiddle + maxRightMiddle;
    // 返回三者最大值
    if (maxMiddle > maxLeft) {
        if (maxMiddle > maxRight) return maxMiddle;
        else return maxLeft;
    } else if (maxLeft > maxRight) return maxLeft;
    else return maxRight;
 }

 /**
  * 影响最大子项和的唯一因素是负数，
  * 如果子项某一部分为负数，一定会使这个子项变小，
  * 如果这小于零的部分在子项的两端，就可以剔除这个部分使子项变大
  *
  * 时间复杂度：N
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
