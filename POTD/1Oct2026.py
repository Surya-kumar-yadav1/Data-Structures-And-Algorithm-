"""
Problem: 20. Valid Parentheses
Difficulty: Easy
Topic: String, Stack

Approach:
- Use a stack to store all opening brackets.
- When an opening bracket is found, push it into the stack.
- When a closing bracket is found, check the top of the stack.
- If the top matches the closing bracket, remove it using pop().
- If it does not match, return False.
- At the end, the stack must be empty for the string to be valid.

Time Complexity: O(n)
Space Complexity: O(n)

Note:
- The stack stores unmatched opening brackets.
- Checking the top of the stack ensures that brackets are closed
  in the correct order.
"""

class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        for ch in s:
            if ch in "({[":
                stack.append(ch)
            else:
                if not stack:
                    return False

                if ch == ')' and stack[-1] == '(':
                    stack.pop()
                elif ch == '}' and stack[-1] == '{':
                    stack.pop()
                elif ch == ']' and stack[-1] == '[':
                    stack.pop()
                else:
                    return False

        return not stack
