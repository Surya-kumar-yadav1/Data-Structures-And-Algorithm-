/*
Problem: 2267. Check if There Is a Valid Parentheses String Path
Difficulty: Hard
Topic: Dynamic Programming, Grid, Matrix

Approach:
- Use Top-Down Dynamic Programming (Memoization) with a 3D state table dp[i][j][bal].
- Track the current cell row (i), column (j), and the running parenthesis balance (bal).
- When standing on a cell, increment 'bal' if it is '(' and decrement if it is ')'.
- If 'bal' drops below 0 at any point, the path is instantly invalid.
- At each cell, the player can move either down (i + 1, j) or right (i, j + 1).
- If the bottom-right corner (m - 1, n - 1) is reached with a balance of exactly 0, 
  a valid path exists.
- An optimization is added at the start to prune grids with an odd total path length.

Time Complexity: O(m * n * (m + n))
Space Complexity: O(m * n * (m + n))
*/

class Solution {
public:
    int dp[105][105][205];

    bool fun(int i, int j, int bal, vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // 1. Boundary check and invalid balance check
        if (i >= m || j >= n || bal < 0) return false;

        // 2. Process current cell's bracket balance
        if (grid[i][j] == '(') bal++;
        else bal--;

        // 3. Re-verify balance (cannot be negative after processing)
        if (bal < 0) return false;

        // 4. Base case: Reached the bottom-right corner
        if (i == m - 1 && j == n - 1) return bal == 0;

        // 5. Return memoized result if already calculated
        if (dp[i][j][bal] != -1) return dp[i][j][bal];

        // 6. Explore right and down directions
        bool right = fun(i, j + 1, bal, grid);
        bool down = fun(i + 1, j, bal, grid);

        return dp[i][j][bal] = right || down;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // Quick pruning: A path from (0,0) to (m-1,n-1) takes exactly (m + n - 1) steps.
        // A valid parenthesis string must have an even length.
        if ((m + n - 1) % 2 != 0) return false;

        memset(dp, -1, sizeof(dp));
        return fun(0, 0, 0, grid);
    }
};
