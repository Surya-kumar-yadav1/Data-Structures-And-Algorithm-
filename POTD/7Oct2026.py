"""
Problem: 301. Remove Invalid Parentheses
Difficulty: Hard
Topic: String, Backtracking, Recursion

Approach:
- First scan from left to right to find an extra ')' that makes the
  string invalid.
- Try removing each possible ')' that can fix this imbalance.
- Avoid removing consecutive ')' at the same level to prevent duplicates.
- After the string is valid from left to right, scan from right to left
  to find any extra '('.
- Remove the necessary '(' and continue recursively.
- When both scans are valid, add the string to the result.

Time Complexity: O(2^n * n)
Space Complexity: O(n)

Note:
- The algorithm removes only invalid parentheses, so it guarantees
  the minimum number of removals.
- Duplicate results are avoided by not removing consecutive identical
  parentheses at the same position.
- O(n) extra space is used for recursion and temporary strings,
  excluding the space needed to store the output.
"""

class Solution:

    def removeInvalidParentheses(self, s: str) -> list[str]:
        res = []
        self.forward(s, res, 0, 0)

        return res

    def forward(self, s, res, li, lj):
        bal = 0

        # Scan from left to right
        for i in range(li, len(s)):
            bal += (s[i] == '(') - (s[i] == ')')

            # String is still valid so far
            if bal >= 0:
                continue

            # Extra ')' found
            for j in range(lj, i + 1):
                if s[j] == ')' and (j == lj or s[j - 1] != ')'):
                    new_string = s[:j] + s[j + 1:]
                    self.forward(new_string, res, i, j)

            return

        # Left to right is valid, now check for extra '('
        self.backward(s, res, len(s) - 1, len(s) - 1)

    def backward(self, s, res, ri, rj):
        bal = 0

        # Scan from right to left
        for i in range(ri, -1, -1):
            bal += (s[i] == ')') - (s[i] == '(')

            # String is still valid from the right
            if bal >= 0:
                continue

            # Extra '(' found
            for j in range(rj, i - 1, -1):
                if s[j] == '(' and (j == rj or s[j + 1] != '('):
                    new_string = s[:j] + s[j + 1:]
                    self.backward(new_string, res, i - 1, j - 1)

            return

        # String is completely valid
        res.append(s)
