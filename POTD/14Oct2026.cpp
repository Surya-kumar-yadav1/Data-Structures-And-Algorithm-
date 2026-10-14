```cpp
/*
Problem: 3723. Maximize Sum of Squares of Digits
Difficulty: Medium
Topic: Math, Greedy

Approach 2:
- If sum < 1 or sum > 9 * num, return an empty string because no valid number can be formed.
- To maximize the sum of squares of digits, we should use as many 9s as possible.
- Calculate n = sum / 9 to find the number of 9s and r = sum % 9 to find the remaining sum.
- Append n copies of '9' to the result.
- If r is non-zero, append it as the next digit.
- Fill the remaining positions with '0' to obtain exactly num digits.
- Placing the largest digits first also gives the maximum number when multiple numbers have the same score.

Time Complexity: O(num)
Space Complexity: O(num)
*/

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum < 1 || sum > 9 * num) return "";

        string res;
        res.reserve(num);

        int n = sum / 9, r = sum % 9;

        res.append(n, '9');
        num -= n;

        if (r) res += '0' + r, --num;

        res.append(num, '0');

        return res;
    }
};
```
