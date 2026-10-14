
"""
Problem: 3723. Maximize Sum of Squares of Digits
Difficulty: Medium
Topic: Math, Greedy

Approach 2:
- If sum < 1 or sum > 9 * num, return an empty string.
- To maximize the sum of squares of digits, use as many 9s as possible.
- Calculate n = sum // 9 to find the number of 9s and r = sum % 9 for the remaining sum.
- Append n copies of '9' to the result.
- If r is non-zero, append it as the next digit.
- Fill the remaining positions with '0' to obtain exactly num digits.

Time Complexity: O(num)
Space Complexity: O(num)
"""

class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        if sum < 1 or sum > 9 * num:
            return ""

        n = sum // 9
        r = sum % 9

        res = "9" * n
        num -= n

        if r:
            res += str(r)
            num -= 1

        res += "0" * num

        return res
