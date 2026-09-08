/*
Problem: 3870. Count Commas in Range
Difficulty: Easy
Topic: Math, Counting

Approach:
- Numbers from 1 to 999 contain no commas.
- Starting from 1000, every number contains at least one comma.
- Therefore, for n >= 1000, we only need to count how many numbers are
  present from 1000 to n.
- The count is:
    n - 1000 + 1
  which simplifies to:
    n - 999
- If n < 1000, there are no commas.

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    int countCommas(int n) {
        if (n < 1000)
            return 0;

        return n - 999;
    }
};
