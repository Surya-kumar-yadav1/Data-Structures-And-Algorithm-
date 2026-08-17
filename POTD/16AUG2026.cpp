```cpp
/*
Problem: 2029. Stone Game IX
Difficulty: Medium
Topic: Array, Math, Game Theory, Counting

Approach:
- Since only the remainder modulo 3 matters, count how many stones have
  values with remainder 0, 1, and 2.
- Let f[0], f[1], and f[2] be the counts of stones with these remainders.
- If f[0] is even, Alice can win only when there is at least one stone
  from both the remainder-1 and remainder-2 groups.
- If f[0] is odd, Alice wins only when the difference between the counts
  of remainder-1 and remainder-2 stones is at least 3.
- The bitwise expression (~f[0] & 1) checks whether f[0] is even.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int f[3] = {0, 0, 0};

        for (auto& s : stones)
            f[s % 3]++;

        if (~f[0] & 1)
            return min(f[1], f[2]) >= 1;

        return abs(f[1] - f[2]) >= 3;
    }
};
```
