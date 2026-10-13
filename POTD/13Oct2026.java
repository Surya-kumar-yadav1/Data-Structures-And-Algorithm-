/*
Problem: 3727. Maximum Alternating Sum of Squares
Difficulty: Medium
Topic: Array, Greedy, Sorting

Approach:
- Convert every element into its square.
- Sort the squared values in ascending order.
- Use two pointers: low at the smallest value and high at the largest.
- Add the largest square and subtract the smallest square.
- Move both pointers toward the center and repeat.
- If one element remains, add it because it occupies a positive position.

Time Complexity: O(n log n)
Space Complexity: O(log n) auxiliary space for sorting

Note:
- Squaring makes all values non-negative, regardless of their signs.
- Larger squares should occupy positive positions, while smaller
  squares should occupy negative positions.
- Use long for the result because the total score may exceed
  the 32-bit integer range.
*/

import java.util.Arrays;

class Solution {
    public long maxAlternatingSum(int[] nums) {
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            nums[i] = Math.abs(nums[i]);
            nums[i] = nums[i] * nums[i];
        }

        Arrays.sort(nums);

        long res = 0;
        int low = 0, high = n - 1;

        while (low < high) {
            res += nums[high];
            res -= nums[low];

            low++;
            high--;
        }

        if (low == high) {
            res += nums[low];
        }

        return res;
    }
}
