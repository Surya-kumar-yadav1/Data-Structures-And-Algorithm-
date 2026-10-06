"""
Problem: 921. Minimum Add to Make Parentheses Valid
Difficulty: Medium
Topic: String, Greedy

Approach:
- Keep track of unmatched opening brackets using open.
- When '(' is found, increase open.
- When ')' is found:
  - If there is an unmatched '(', match it and decrease open.
  - Otherwise, this ')' has no matching '(', so we need to insert
    an opening bracket before it. Increase ans.
- After processing the whole string, any remaining opening brackets
  need a closing bracket.
- Therefore, the total answer is ans + open.

Time Complexity: O(n)
Space Complexity: O(1)

Note:
- open = number of unmatched '(' brackets.
- ans = number of ')' brackets that need a matching '(' inserted.
"""

class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        open = 0
        ans = 0

        for c in s:
            if c == '(':
                open += 1
            else:
                if open - 1 < 0:
                    ans += 1
                else:
                    open -= 1

        return open + ans
