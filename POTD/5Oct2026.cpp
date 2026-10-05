/*
Problem: 856. Score of Parentheses
Difficulty: Medium
Topic: String, Stack, Counting

Approach:
- Maintain the current nesting depth using bal.
- When '(' is found, increase the depth.
- When ')' is found, decrease the depth first.
- If the current pair is "()", it contributes a score of 1
  multiplied by 2 for every outer level.
- Therefore, when s[i] == ')' and s[i - 1] == '(', add 2^bal.
- Use 1 << bal to calculate 2^bal efficiently.

Time Complexity: O(n)
Space Complexity: O(1)

Note:
- bal represents the nesting depth after processing the closing bracket.
- A pair "()" at depth bal contributes 2^bal.
- For example, "(())" has the inner "()" at depth 1, so its score is 2^1 = 2.
*/

class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        int bal = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                bal++;
            } 
            else {
                bal--;

                if (s[i - 1] == '(') {
                    ans += 1 << bal;
                }
            }
        }

        return ans;
    }
};
