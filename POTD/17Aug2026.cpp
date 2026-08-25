/*
Problem: 1563. Stone Game V
Difficulty: Hard
Topic: Array, Dynamic Programming, Prefix Sum, Recursion

Approach:
- Let dp[l][r] represent the maximum score Alice can obtain from the
  subarray stoneValue[l...r].
- Use prefix sums to calculate the sum of any subarray in O(1).
- For every possible split position m, divide the current row into:
    Left  = stoneValue[l...m]
    Right = stoneValue[m+1...r]
- If Left <= Right, Bob can discard the right row, so Alice gains Left
  and continues with the left part.
- If Left >= Right, Bob can discard the left row, so Alice gains Right
  and continues with the right part.
- When both sums are equal, both choices are possible, so we consider
  both.
- Memoization avoids solving the same subproblem multiple times.
- The pruning condition stops checking further splits when even twice
  the smaller sum cannot improve the current answer.

Time Complexity: O(n^3) in the worst case
Space Complexity: O(n^2)
*/

int dp[501][501];
int Sum[501];

class Solution {
public:
    static int f(int l, int r) {
        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;

        for (int m = l; m < r; m++) {
            int Lsum = Sum[m + 1] - Sum[l];
            int Rsum = Sum[r + 1] - Sum[m + 1];

            if (Lsum <= Rsum)
                ans = max(ans, Lsum + f(l, m));

            if (Lsum >= Rsum)
                ans = max(ans, Rsum + f(m + 1, r));

            // Pruning branch
            if (2 * min(Lsum, Rsum) <= ans)
                break;
        }

        return dp[l][r] = ans;
    }

    static int stoneGameV(vector<int>& stoneValue) {
        const int n = stoneValue.size();

        // Build prefix sum array
        partial_sum(stoneValue.begin(), stoneValue.end(), Sum + 1);

        // Initialize DP table
        for (int i = 0; i <= n; i++)
            memset(dp[i], -1, sizeof(int) * (n + 1));

        return f(0, n - 1);
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
