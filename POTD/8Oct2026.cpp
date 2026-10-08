/*
Problem: 1021. Remove Outermost Parentheses
Difficulty: Easy
Topic: String, Stack, Counting

Approach:
- Keep track of the current nesting level using balance.
- For every '(' increase balance, and for every ')' decrease balance.
- The outermost '(' of a primitive VPS is at balance 0 -> 1, so skip it.
- The outermost ')' brings balance from 1 -> 0, so skip it.
- Keep all other parentheses.
- The result is stored directly inside the original string to save extra space.

Time Complexity: O(n)
Space Complexity: O(1)

Note:
- balance represents the current nesting depth.
- A parenthesis is outermost when:
  - '(' changes balance from 0 to 1.
  - ')' changes balance from 1 to 0.
- The solution modifies the input string in-place.
*/

class Solution {
public:
    string removeOuterParentheses(string& s) {
        int n = s.size();
        int balance = 0;
        int j = 0;

        for (int i = 0; i < n; i++) {
            char c = s[i];

            balance += (c == '(') - (c == ')');

            // Skip the outermost parentheses
            if ((balance == 1 && c == '(') ||
                (balance == 0 && c == ')')) {
                continue;
            }

            s[j++] = c;
        }

        s.resize(j);
        return s;
    }
};
