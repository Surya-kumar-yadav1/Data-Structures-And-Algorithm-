/*
Problem: 22. Generate Parentheses
Difficulty: Medium
Topic: String, Backtracking

Approach:
- Use recursion/backtracking to build all valid parentheses combinations.
- Keep track of the number of opening and closing brackets used.
- Add '(' only when open < n.
- Add ')' only when close < open, so the string always remains valid.
- When both open and close reach n, add the current string to the answer.

Time Complexity: O(4^n / sqrt(n))
Space Complexity: O(n)

Note:
- The recursion explores all possible valid combinations.
- The condition close < open prevents invalid strings such as ")(".
*/

class Solution {
public:
    void f(int open, int close, int n, string s, vector<string>& ans) {
        if (open == n && close == n) {
            ans.push_back(s);
            return;
        }

        if (open < n) {
            f(open + 1, close, n, s + "(", ans);
        }

        if (close < open) {
            f(open, close + 1, n, s + ")", ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        f(0, 0, n, "", ans);
        return ans;
    }
};
