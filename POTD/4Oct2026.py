"""
Problem: 678. Valid Parenthesis String
Difficulty: Medium
Topic: String, Greedy

Approach:
- Maintain a range [low, high] representing the possible number of
  unmatched opening brackets.
- '(' increases both low and high because it must be an opening bracket.
- ')' decreases both low and high because it must close an opening bracket.
- '*' can act as '(', ')' or an empty string:
  - low decreases because '*' can act as ')'.
  - high increases because '*' can act as '('.
- low cannot be negative, so set it to 0.
- If high becomes negative, there are more closing brackets than possible
  opening brackets, so the string is invalid.
- At the end, low must be 0, meaning it is possible to balance all brackets.

Time Complexity: O(n)
Space Complexity: O(1)

Note:
- low = minimum possible number of unmatched '('.
- high = maximum possible number of unmatched '('.
- The range allows us to handle all possible meanings of '*'.
"""

class Solution:
    def checkValidString(self, s: str) -> bool:
        low = 0
        high = 0

        for c in s:
            if c == '(':
                low += 1
                high += 1

            elif c == ')':
                low -= 1
                high -= 1

            else:
                low -= 1
                high += 1

            low = max(low, 0)

            if high < 0:
                return False

        return low == 0
