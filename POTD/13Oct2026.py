"""
Problem: 3727. Maximum Alternating Sum of Squares
Difficulty: Medium
Topic: Array, Greedy, Sorting

Approach:
- Convert every element into its square.
- Sort the squared values in ascending order.
- Use two pointers: low at the smallest value and high at the largest.
- Add the largest square and subtract the smallest square.
- Move both pointers toward the center and repeat.
- If one element remains, add it because it occupies a positive position.

Time Complexity: O(n log n)
Space Complexity: O(n) auxiliary space for Python's sorting algorithm

Note:
- Squaring makes all values non-negative, regardless of their signs.
- Larger squares should occupy positive positions, while smaller
  squares should occupy negative positions.
- Python integers can handle the large resulting score automatically.
"""

class Solution:
    def maxAlternatingSum(self, nums: list[int]) -> int:
        n = len(nums)

        for i in range(n):
            nums[i] = abs(nums[i])
            nums[i] = nums[i] * nums[i]

        nums.sort()

        res = 0
        low, high = 0, n - 1

        while low < high:
            res += nums[high]
            res -= nums[low]

            low += 1
            high -= 1

        if low == high:
            res += nums[low]

        return res
