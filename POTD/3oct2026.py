"""
Problem: 32. Longest Valid Parentheses
Difficulty: Hard
Topic: String, Two Pass, Counting

Approach:
- Traverse the string from left to right and count '(' and ')'.
- '(' has even ASCII value and ')' has odd ASCII value, so
  ord(s[i]) & 1 can be used to separate the two counts.
- When the number of '(' and ')' becomes equal, we have a valid
  parentheses substring, so update the maximum length.
- If ')' becomes greater than '(', the current substring cannot
  become valid, so reset both counts.
- Repeat the same process from right to left to handle cases where
  '(' is greater than ')' in the left-to-right traversal.

Time Complexity: O(n)
Space Complexity: O(1)

Note:
- ASCII value of '(' is 40 (even), while ')' is 41 (odd).
- Therefore, ord(s[i]) & 1 gives 0 for '(' and 1 for ')'.
- Two passes are needed to handle both types of imbalance.
"""

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        f = [0, 0]
        b = [0, 0]
        res = 0
        n = len(s)

        # Left to right
        for i in range(n):
            f[ord(s[i]) & 1] += 1

            if f[0] == f[1]:
                res = max(res, f[1] << 1)

            if f[0] < f[1]:
                f[0] = 0
                f[1] = 0

            # Right to left
            b[ord(s[n - 1 - i]) & 1] += 1

            if b[0] == b[1]:
                res = max(res, b[1] << 1)

            if b[0] > b[1]:
                b[0] = 0
                b[1] = 0

        return res
