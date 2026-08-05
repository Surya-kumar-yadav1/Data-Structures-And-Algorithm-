"""
Problem: 3731. Find Missing Elements
Difficulty: Easy
Topic: Array, Sorting

Approach:
- Sort the array in ascending order.
- Traverse the sorted array while maintaining the expected value starting from the smallest element.
- If the expected value is missing, add it to the answer and continue checking.
- Otherwise, move to the next element.
- The collected values represent all missing integers in the original range.

Time Complexity: O(n log n)
Space Complexity: O(1) (excluding the output array)
"""

class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        nums.sort()

        cnt = nums[0]
        ans = []

        i = 0
        while i < len(nums):
            if cnt != nums[i]:
                ans.append(cnt)
            else:
                i += 1
            cnt += 1

        return ans
