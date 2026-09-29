/*
Problem: 1614. Maximum Nesting Depth of the Parentheses
Difficulty: Easy
Topic: String, Stack / Counter

Approach:
- Maintain a running counter 'current_depth' to track the balance of open parentheses.
- Traverse the string character by character:
  - If the character is '(', increment 'current_depth'.
  - If the character is ')', decrement 'current_depth'.
- Track the maximum value 'max_depth' achieved by 'current_depth' at any point.
- Since the input string is guaranteed to be a valid parentheses string, we don't
  need to maintain a physical stack array, reducing memory usage to O(1).

Time Complexity: O(n) where n is the length of the string.
Space Complexity: O(1) auxiliary space.
*/

class Solution {
public:
    int maxDepth(string s) {
        int max_depth = 0;
        int current_depth = 0;

        for (char c : s) {
            if (c == '(') {
                current_depth++;
                max_depth = max(max_depth, current_depth);
            } else if (c == ')') {
                current_depth--;
            }
        }

        return max_depth;
    }
};
