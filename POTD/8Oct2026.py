"""
Problem: 1021. Remove Outermost Parentheses
Difficulty: Easy
Topic: String, Stack, Counting

Approach:
- Keep track of the current nesting level using balance.
- For every '(' increase balance, and for every ')' decrease balance.
- The outermost '(' of a primitive VPS is at balance 0 -> 1, so skip it.
- The outermost ')' brings balance from 1 -> 0, so skip it.
- Keep all other parentheses.
- Store the remaining characters in a list and join them at the end.

Time Complexity: O(n)
Space Complexity: O(n)

Note:
- balance represents the current nesting depth.
- A parenthesis is outermost when:
  - '(' changes balance from 0 to 1.
  - ')' changes balance from 1 to 0.
"""

class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        balance = 0
        ans = []

        for c in s:
            if c == '(':
                balance += 1
            else:
                balance -= 1

            # Skip the outermost parentheses
            if (balance == 1 and c == '(') or \
               (balance == 0 and c == ')'):
                continue

            ans.append(c)

        return ''.join(ans)
