"""
Problem: 3871. Count Commas in Range II
Difficulty: Medium
Topic: Math, Counting

Approach:
- Numbers from 1 to 999 contain 0 commas.
- Numbers from 1000 to 999999 contain 1 comma.
- Numbers from 1000000 to 999999999 contain 2 commas.
- Numbers from 1000000000 to 999999999999 contain 3 commas.
- In general, every time we add 3 more digits, the number of commas
  increases by 1.

- For each range:
    start = 1000, 1000000, 1000000000, ...
    end   = start * 1000 - 1

- Count how many numbers are present in the current range:
    end - start + 1

- Each number in that range has the same number of commas, so:
    count of numbers * number of commas

- We repeat this until start > n.

Time Complexity:
- Each iteration increases start by a factor of 1000.
- Therefore, the number of iterations is O(log_1000(n)).
- In standard Big-O notation, this is O(log n).

Space Complexity:
- We only use a few variables.
- Therefore, space complexity is O(1).
"""


class Solution:
    def countCommas(self, n: int) -> int:
        ans = 0
        start = 1000
        commas = 1

        while start <= n:
            end = min(n, start * 1000 - 1)

            ans += (end - start + 1) * commas

            start *= 1000
            commas += 1

        return ans
