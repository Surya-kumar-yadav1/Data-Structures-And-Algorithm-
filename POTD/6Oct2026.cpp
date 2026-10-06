/*
Problem: 921. Minimum Add to Make Parentheses Valid
Difficulty: Medium
Topic: String, Greedy

Approach:
- Keep track of unmatched opening brackets using open.
- When '(' is found, increase open.
- When ')' is found:
  - If there is an unmatched '(', match it and decrease open.
  - Otherwise, this ')' has no matching '(', so we need to insert
    an opening bracket before it. Increase ans.
- After processing the whole string, any remaining opening brackets
  need a closing bracket.
- Therefore, the total answer is ans + open.

Time Complexity: O(n)
Space Complexity: O(1)

Note:
- open = number of unmatched '(' brackets.
- ans = number of ')' brackets that need a matching '(' inserted.
*/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int ans = 0;

        for (char c : s) {
            if (c == '(') {
                open++;
            } 
            else {
                if (open - 1 < 0) {
                    ans++;
                } 
                else {
                    open--;
                }
            }
        }

        return open + ans;
    }
};
