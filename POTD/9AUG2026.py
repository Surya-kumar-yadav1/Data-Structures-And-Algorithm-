"""
Problem: 1140. Stone Game II
Difficulty: Medium
Topic: Dynamic Programming, Recursion, Game Theory

Approach:
- Use DP with three states:
  person -> whose turn it is
  i      -> current pile index
  M      -> maximum number of piles allowed
- Alice maximizes her total stones.
- Bob minimizes Alice's total stones.
- On each turn, try taking X piles where 1 <= X <= 2*M.
- Update M = max(M, X).
- Memoization avoids recalculating states.

Time Complexity: O(n³)
Space Complexity: O(n²)
"""

class Solution:
    def solve(self, person, i, M, piles, dp):
        n = len(piles)

        if i >= n:
            return 0

        if dp[person][i][M] != -1:
            return dp[person][i][M]

        if person == 1:
            result = -1
        else:
            result = float('inf')

        stones = 0

        for x in range(1, min(2 * M, n - i) + 1):

            if person == 1:
                stones += piles[i + x - 1]

                result = max(
                    result,
                    stones + self.solve(
                        0, i + x, max(M, x), piles, dp
                    )
                )

            else:
                result = min(
                    result,
                    self.solve(
                        1, i + x, max(M, x), piles, dp
                    )
                )

        dp[person][i][M] = result
        return result

    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)

        dp = [[[-1] * (n + 1) for _ in range(n)]
              for _ in range(2)]

        return self.solve(1, 0, 1, piles, dp)
