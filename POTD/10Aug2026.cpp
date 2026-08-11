/*
Problem: 1510. Stone Game IV
Difficulty: Hard
Topic: Dynamic Programming, Game Theory

Approach:
- Use DP where dp[i] represents whether the current player can win
  when there are i stones remaining.
- For every state j, try removing every possible square number i².
- If there exists a move such that the opponent reaches a losing state,
  then dp[j] is true.
- If all possible moves lead to winning states for the opponent,
  then dp[j] remains false.
- Finally, dp[n] tells whether Alice can win.

Time Complexity: O(n√n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);

        for (int j = 1; j <= n; j++) {
            for (int i = 1; i * i <= j; i++) {
                if (dp[j - (i * i)] == false) {
                    dp[j] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
