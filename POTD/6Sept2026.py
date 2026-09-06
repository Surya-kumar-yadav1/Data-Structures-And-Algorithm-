"""
Problem: 115. Distinct Subsequences
Difficulty: Hard
Topic: Dynamic Programming, String

Approach:
- Let prev[j] represent the number of distinct subsequences of the processed
  part of s that form the first j characters of t.
- Initially, prev[0] = 1 because there is exactly one way to form an empty
  string: by choosing no characters.
- Traverse s character by character and update the DP array from right to left.
- If s[i - 1] == t[j - 1], we have two choices:
    1. Use s[i - 1] to match t[j - 1]  -> prev[j - 1]
    2. Ignore s[i - 1]                 -> prev[j]
  Therefore:
    prev[j] = prev[j - 1] + prev[j]
- If the characters do not match, the value remains unchanged.
- Updating from right to left ensures that prev[j - 1] still represents the
  previous state when calculating prev[j].

Time Complexity: O(n * m)
Space Complexity: O(m)
"""

class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        n = len(s)
        m = len(t)

        prev = [0] * (m + 1)
        prev[0] = 1

        for i in range(1, n + 1):
            for j in range(m, 0, -1):
                if s[i - 1] == t[j - 1]:
                    prev[j] = prev[j - 1] + prev[j]

        return prev[m]
