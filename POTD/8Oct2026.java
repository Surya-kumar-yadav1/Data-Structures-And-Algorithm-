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
- Build the result using StringBuilder.

Time Complexity: O(n)
Space Complexity: O(n)

Note:
- balance represents the current nesting depth.
- A parenthesis is outermost when:
  - '(' changes balance from 0 to 1.
  - ')' changes balance from 1 to 0.
*/

class Solution {
    public String removeOuterParentheses(String s) {
        int balance = 0;
        StringBuilder ans = new StringBuilder();

        for (char c : s.toCharArray()) {
            balance += (c == '(') ? 1 : -1;

            // Skip the outermost parentheses
            if ((balance == 1 && c == '(') ||
                (balance == 0 && c == ')')) {
                continue;
            }

            ans.append(c);
        }

        return ans.toString();
    }
}
