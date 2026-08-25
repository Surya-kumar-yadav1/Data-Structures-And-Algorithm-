/*
Problem: 1872. Stone Game VIII
Difficulty: Hard
Topic: Array, Prefix Sum, Dynamic Programming, Game Theory

Approach:
- Convert the array into a prefix sum array.
  A[i] represents the sum of stones from index 0 to i.
- The important observation is that after Alice makes a move, the
  remaining state can always be represented by choosing some prefix
  sum A[i] where i > 0.
- Let `ans` represent the best score difference for the current state.
- Initially, when all stones are merged, the score difference is
  A[n-1], because Alice can choose all remaining stones except that
  at least two stones must be chosen initially.
- Process the prefix sums from right to left.
- For every possible split at i:
      current_difference = A[i] - ans
  because the player making the current move gains A[i], while the
  opponent can subsequently achieve `ans`.
- Therefore the optimal transition is:
      ans = max(ans, A[i] - ans)
- The loop starts from n-2 and stops at 1 because at least two stones
  must be chosen in the first move, so prefix index 0 is never a valid
  state.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int stoneGameVIII(vector<int>& A) {
        int n = A.size();

        // Convert A into prefix sums.
        for (int i = 1; i < n; i++)
            A[i] += A[i - 1];

        // Start with the sum of all stones.
        int ans = A.back();

        // Try every possible prefix from right to left.
        for (int i = n - 2; i > 0; i--)
            ans = max(ans, A[i] - ans);

        return ans;
    }
};
