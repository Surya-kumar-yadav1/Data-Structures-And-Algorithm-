"""
Problem: 2333. Minimum Sum of Squared Difference
Difficulty: Medium
Topic: Array, Greedy, Counting, Bucket Sort

Approach:
- Calculate the absolute difference between corresponding elements
  of nums1 and nums2 and find the maximum difference M.
- Store the frequency of each difference in a bucket array.
- Use k = k1 + k2 as the total number of allowed operations.
- Greedily reduce the largest differences first because reducing
  larger differences gives the greatest decrease in the squared sum.
- For each difference i, move as many elements as possible from
  bucket[i] to bucket[i - 1], limited by the remaining operations.
- Finally, calculate the sum of squared differences using the
  remaining bucket frequencies.

Time Complexity: O(n + M)
Space Complexity: O(n + M)

Note:
- M is the maximum absolute difference.
- Each operation reduces one difference by 1.
- Bucket sort avoids using a priority queue and processes all
  possible difference values efficiently.
"""

class Solution:
    def minSumSquareDiff(self, nums1: list[int], nums2: list[int],
                         k1: int, k2: int) -> int:
        n = len(nums1)
        k = k1 + k2

        diff = [abs(nums1[i] - nums2[i]) for i in range(n)]
        M = max(diff)

        bucket = [0] * (M + 1)

        for x in diff:
            bucket[x] += 1

        for i in range(M, 0, -1):
            if k == 0:
                break

            take = min(bucket[i], k)

            bucket[i] -= take
            bucket[i - 1] += take
            k -= take

        ans = 0

        for i in range(1, M + 1):
            ans += bucket[i] * i * i

        return ans
