"""
Problem: 1111. Maximum Nesting Depth of Two Valid Parentheses Strings
Difficulty: Medium
Topic: String, Greedy

Approach:
- Track the current nesting depth while traversing the string.
- For every bracket, assign it to one of the two groups based on
  the parity of the current depth.
- Use depth % 2 to alternate between group 0 and group 1.
- For '(' increase the depth first, then assign its group.
- For ')' assign its group first, then decrease the depth.
- This distributes the nesting levels between the two groups and
  minimizes the maximum nesting depth.

Time Complexity: O(n)
Space Complexity: O(n)

Note:
- The extra O(n) space is used for the answer array.
- The actual depth tracking uses only O(1) extra space.
"""

class Solution:
    def maxDepthAfterSplit(self, seq: str) -> list[int]:
        ans = []
        depth = 0

        for c in seq:
            if c == '(':
                depth += 1
                ans.append(depth % 2)
            else:
                ans.append(depth % 2)
                depth -= 1

        return ans
