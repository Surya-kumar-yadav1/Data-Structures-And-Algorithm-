```cpp id="m7k2pd"
/*
Problem: 3702. Longest Subsequence With Non-Zero Bitwise XOR
Difficulty: Medium
Topic: Array, Bit Manipulation, XOR

Approach:
- First check whether the array contains at least one non-zero element.
- Calculate the XOR of all elements in the array.
- If the total XOR is non-zero, the entire array itself is a valid subsequence,
  so the answer is n.
- If the total XOR is zero but there is at least one non-zero element, remove
  any one non-zero element. The XOR of the remaining elements becomes non-zero,
  so the answer is n - 1.
- If all elements are zero, every subsequence has XOR equal to zero, so the
  answer is 0.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        auto tot = 0, nonZero = 0;

        for (auto& n : nums) {
            nonZero |= n > 0;
            tot ^= n;
        }

        return nonZero * (nums.size() - !tot);
    }
};
```
