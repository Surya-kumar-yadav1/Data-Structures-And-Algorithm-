/*
Problem: 1140. Stone Game II
Difficulty: Medium
Topic: Dynamic Programming, Recursion, Game Theory

Approach:
- Use DP with three states:
  person -> whose turn it is
  i      -> current pile index
  M      -> maximum number of piles allowed based on previous moves
- Alice tries to maximize her total stones.
- Bob tries to minimize Alice's total stones.
- For every turn, try taking X piles where 1 <= X <= 2*M.
- After taking X piles, update M = max(M, X).
- Memoization avoids recalculating the same state.

Time Complexity: O(n³)
Space Complexity: O(n²)
*/

class Solution {
public:
    int vec[2][101][101];

    int solve(int person, int i, int M, vector<int>& piles) {
        int n = piles.size();

        if (i >= n)
            return 0;

        if (vec[person][i][M] != -1)
            return vec[person][i][M];

        int result = (person == 1) ? -1 : INT_MAX;
        int stones = 0;

        for (int x = 1; x <= min(2 * M, n - i); x++) {

            if (person == 1) {
                stones += piles[i + x - 1];

                result = max(
                    result,
                    stones + solve(0, i + x, max(M, x), piles)
                );
            }
            else {
                result = min(
                    result,
                    solve(1, i + x, max(M, x), piles)
                );
            }
        }

        return vec[person][i][M] = result;
    }

    int stoneGameII(vector<int>& piles) {
        memset(vec, -1, sizeof(vec));

        return solve(1, 0, 1, piles);
    }
};
