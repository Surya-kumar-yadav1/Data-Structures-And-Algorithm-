"""
Problem: 22. Generate Parentheses
Difficulty: Medium
Topic: String, Backtracking

Approach:
- Use recursion/backtracking to build all valid parentheses combinations.
- Keep track of the number of opening and closing brackets used.
- Add '(' only when open < n.
- Add ')' only when close < open, so the string always remains valid.
- When both open and close reach n, add the current string to the answer.

Time Complexity: O(4^n / sqrt(n))
Space Complexity: O(n)

Note:
- The recursion explores all possible valid combinations.
- The condition close < open prevents invalid strings such as ")(".
"""

class Solution:
    def f(self, open_count, close_count, n, s, ans):
        if open_count == n and close_count == n:
            ans.append(s)
            return

        if open_count < n:
            self.f(open_count + 1, close_count, n, s + "(", ans)

        if close_count < open_count:
            self.f(open_count, close_count + 1, n, s + ")", ans)

    def generateParenthesis(self, n: int) -> list[str]:
        ans = []
        self.f(0, 0, n, "", ans)
        return ans
