/* 
Problem: 1658. Minimum Operations to Reduce X to Zero
Difficulty: Medium
Topic: Array, Sliding Window, Two Pointer

Approach:
- Let total be the sum of all elements in nums.
- If we remove elements from the left and right whose sum is x,
  the remaining subarray must have sum = total - x.
- So, instead of finding the removed elements, find the longest
  contiguous subarray whose sum is exactly total - x.
- Use a sliding window:
  - Expand the window by adding nums[j].
  - If the window sum becomes greater than the target, move the
    left pointer forward until the sum becomes valid.
  - If the window sum equals the target, update the longest window.
- If the longest valid subarray has length `best`, then the number
  of removed elements is `n - best`.
- Special cases:
  - If total - x < 0, it is impossible.
  - If total - x == 0, all elements must be removed, so answer is n.
 
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int minOperations(vector<int>& A, int x) {
        int k = reduce(A.begin(), A.end()) - x;
        int n = A.size();

        if (k < 0)
            return -1;

        if (k == 0)
            return n;

        int best = -1;
        int i = 0;
        int sum = 0;

        for (int j = 0; j < n; j++) {
            sum += A[j];

            while (sum > k)
                sum -= A[i++];

            if (sum == k)
                best = max(best, j - i + 1);
        }

        return best + 1 ? n - best : -1;
    }
};
