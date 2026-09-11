"""
Problem: 3483. Unique 3-Digit Even Numbers
Difficulty: Easy
Topic: Array, Hash Set, Brute Force

Approach:
- Try every possible choice of the hundreds, tens, and units digits.
- The hundreds digit cannot be 0 because the number must be a three-digit number.
- The three positions must use different copies of digits, so we ensure
  that the selected indices are distinct.
- The units digit must be even, so we only accept digits divisible by 2.
- Add every valid number to a set to remove duplicates.
- The size of the set gives the number of distinct three-digit even numbers.

Time Complexity: O(n^3)
Space Complexity: O(n^3)
"""

class Solution:
    def totalNumbers(self, digits: list[int]) -> int:
        n = len(digits)
        st = set()

        for i in range(n):
            if digits[i] == 0:
                continue

            for j in range(n):
                if i == j:
                    continue

                for k in range(n):
                    if i == k or j == k:
                        continue

                    if digits[k] % 2 != 0:
                        continue

                    num = digits[i] * 100 + digits[j] * 10 + digits[k]
                    st.add(num)

        return len(st)
