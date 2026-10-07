/*
Problem: 301. Remove Invalid Parentheses
Difficulty: Hard
Topic: String, Backtracking, Recursion

Approach:
- First scan from left to right to find an extra ')' that makes the
  string invalid.
- Try removing each possible ')' that can fix this imbalance.
- Avoid removing consecutive ')' at the same level to prevent duplicates.
- After the string is valid from left to right, scan from right to left
  to find any extra '('.
- Remove the necessary '(' and continue recursively.
- When both scans are valid, add the string to the result.

Time Complexity: O(2^n * n)
Space Complexity: O(n)

Note:
- The algorithm removes only invalid parentheses, so it guarantees
  the minimum number of removals.
- Duplicate results are avoided by not removing consecutive identical
  parentheses at the same position.
- O(n) extra space is used for recursion and temporary strings,
  excluding the space needed to store the output.
*/

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        forward(s, res, 0, 0);

        return res;
    }

private:
    void forward(string s, vector<string>& res, int li, int lj) {
        int bal = 0;

        // Scan from left to right
        for (int i = li; i < s.length(); i++) {
            bal += (s[i] == '(') - (s[i] == ')');

            // String is still valid so far
            if (bal >= 0)
                continue;

            // Extra ')' found
            for (int j = lj; j <= i; j++) {
                if (s[j] == ')' && (j == lj || s[j - 1] != ')')) {
                    forward(
                        s.substr(0, j) + s.substr(j + 1),
                        res,
                        i,
                        j
                    );
                }
            }

            return;
        }

        // Left to right is valid, now check for extra '('
        backward(s, res, s.length() - 1, s.length() - 1);
    }

    void backward(string s, vector<string>& res, int ri, int rj) {
        int bal = 0;

        // Scan from right to left
        for (int i = ri; i >= 0; i--) {
            bal += (s[i] == ')') - (s[i] == '(');

            // String is still valid from the right
            if (bal >= 0)
                continue;

            // Extra '(' found
            for (int j = rj; j >= i; j--) {
                if (s[j] == '(' && (j == rj || s[j + 1] != '(')) {
                    backward(
                        s.substr(0, j) + s.substr(j + 1),
                        res,
                        i - 1,
                        j - 1
                    );
                }
            }

            return;
        }

        // String is completely valid
        res.push_back(s);
    }
};
