/* 
Problem: 3903. Smallest Stable Index I 
Difficulty: Easy 
Topic: Array, Prefix Maximum, Suffix Minimum 
 
Approach: 
- For every index i, we need:
    max(nums[0..i]) - min(nums[i..n-1])
- Precompute the suffix minimum for every index. 
- suf[i] stores the minimum value from index i to the end of the array. 
- Traverse the array from left to right while maintaining maxSoFar, 
  which stores the maximum value from nums[0] to nums[i]. 
- At each index, calculate:
    maxSoFar - suf[i]
- The first index where this value is less than or equal to k is the 
  smallest stable index, so return it immediately. 
- If no index satisfies the condition, return -1. 
 
Time Complexity: O(n) 
Space Complexity: O(n) 
*/ 
 
class Solution {
public:
    inline static int suf[100];

    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        suf[n - 1] = nums.back();

        for (int i = n - 2; i >= 0; i--)
            suf[i] = min(suf[i + 1], nums[i]);

        int maxSoFar = 0;

        for (int i = 0; i < n; i++) {
            maxSoFar = max(maxSoFar, nums[i]);

            if (maxSoFar - suf[i] <= k)
                return i;
        }

        return -1;
    }
};
