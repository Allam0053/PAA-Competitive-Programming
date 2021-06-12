#include <stdio.h>
int main () {
    int start, end, minimumSum=54, currentSum, countMinimumSum=0; // 1 - 1.000.000  => 999.999 => 54
    scanf("%d%d", &start, &end);
    //count digits
    while (start<=end) {
        int temp = start;
        currentSum = 0;
        while (temp>0) {
            currentSum += (temp%10);
            temp/=10;
        }
        if (currentSum < minimumSum) {
            minimumSum = currentSum;
            countMinimumSum = 1;
        } else if (currentSum == minimumSum) {
            countMinimumSum++;
        }
        start++;
    }
    printf("%d\n", countMinimumSum);
    return 0;
}