/*
Problem: 3731. Find Missing Elements
Difficulty: Easy
Topic: Array, Sorting

Approach:
- Sort the array in ascending order.
- Traverse the sorted array while maintaining the expected value starting from the smallest element.
- If the expected value is missing, add it to the answer and continue checking.
- Otherwise, move to the next element.
- The collected values represent all missing integers in the original range.

Time Complexity: O(n log n)
Space Complexity: O(1) (excluding the output array)
*/

#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int* findMissingElements(int* nums, int numsSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), compare);

    int *ans = (int *)malloc(sizeof(int) * (nums[numsSize - 1] - nums[0]));
    *returnSize = 0;

    int cnt = nums[0];

    for (int i = 0; i < numsSize; i++) {
        if (cnt != nums[i]) {
            ans[(*returnSize)++] = cnt;
            i--;
        }
        cnt++;
    }

    return ans;
}
