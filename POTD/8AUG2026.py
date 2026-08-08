"""
Problem: 3302. Find the Lexicographically Smallest Valid Sequence
Difficulty: Medium
Topic: String, Greedy, Two Pointers

Approach:
- Traverse word1 from right to left and store the latest possible index
  for matching each character of word2.
- Traverse word1 from left to right and greedily construct the answer.
- If the current character matches word2[j], select it.
- Otherwise, use the one allowed character change if enough characters
  remain to complete word2.
- By always choosing the earliest possible index, we obtain the
  lexicographically smallest valid sequence.

Time Complexity: O(n + m)
Space Complexity: O(m)
"""

class Solution:
    def validSequence(self, word1: str, word2: str) -> List[int]:
        n = len(word1)
        m = len(word2)

        last = [-1] * m

        i = n - 1
        j = m - 1

        while i >= 0 and j >= 0:
            if word1[i] == word2[j]:
                last[j] = i
                j -= 1

            i -= 1

        ans = []
        canSkip = True
        j = 0

        for i in range(n):
            if j >= m:
                break

            if word1[i] == word2[j]:
                ans.append(i)
                j += 1

            elif canSkip and (j == m - 1 or i < last[j + 1]):
                canSkip = False
                ans.append(i)
                j += 1

        if j == m:
            return ans

        return []
