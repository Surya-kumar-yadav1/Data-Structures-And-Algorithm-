"""
Problem: 1927. Sum Game
Difficulty: Medium
Topic: String, Math, Game Theory

Approach:
- Divide the string into two halves and calculate:
    sumL = sum of known digits in the left half
    sumR = sum of known digits in the right half
    qL   = number of '?' in the left half
    qR   = number of '?' in the right half

- Alice wants the final two sums to be different, while Bob wants them
  to be equal.

- If there are no '?' characters, the result is simply:
      sumL != sumR

- If the total number of '?' is odd, Alice always wins.
  This is because Alice moves first and can always create an imbalance
  that Bob cannot completely cancel.

- If the number of '?' is even:
    1. When qL == qR, the unknown positions are balanced between the
       two halves. Bob can mirror Alice's moves, so Alice wins only if
       the current sums are already different.
    2. Otherwise, the unequal number of '?' creates an unavoidable
       advantage for one side. Each pair of moves can change the
       difference by at most 9, leading to the condition:
           2 * (sumL - sumR) != 9 * (qR - qL)

- If this equality holds, Bob can force the two sums to become equal.
  Otherwise, Alice wins.

Time Complexity: O(n)
Space Complexity: O(1)
"""

class Solution:
    def sumGame(self, num: str) -> bool:
        n = len(num)

        sumL = 0
        sumR = 0
        qL = 0
        qR = 0

        # Calculate known sums and count '?' in each half.
        for i in range(n):
            if i < n // 2:
                if num[i] == '?':
                    qL += 1
                else:
                    sumL += int(num[i])
            else:
                if num[i] == '?':
                    qR += 1
                else:
                    sumR += int(num[i])

        # Case 1: No '?' characters.
        if qL + qR == 0:
            return sumL != sumR

        # Case 2: Odd number of '?' characters.
        if (qL + qR) % 2:
            return True

        # Case 3: Even number of '?' characters.

        # Case 3a: Equal number of '?' on both sides.
        if qL == qR:
            return sumL != sumR

        # Case 3b: Different number of '?' on the two sides.
        return 2 * (sumL - sumR) != 9 * (qR - qL)
