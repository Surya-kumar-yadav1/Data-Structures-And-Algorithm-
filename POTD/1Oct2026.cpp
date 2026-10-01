/*
Problem: 20. Valid Parentheses
Difficulty: Easy
Topic: String, Stack

Approach:
- Use a stack to store all opening brackets.
- When an opening bracket is found, push it into the stack.
- When a closing bracket is found, check the top of the stack.
- If the top matches the closing bracket, remove it using pop().
- If it does not match, return false.
- At the end, the stack must be empty for the string to be valid.

Time Complexity: O(n)
Space Complexity: O(n)

Note:
- The stack stores unmatched opening brackets.
- Checking the top of the stack ensures that brackets are closed
  in the correct order.
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if (st.empty()) {
                    return false;
                }

                if (ch == ')' && st.top() == '(') {
                    st.pop();
                } 
                else if (ch == '}' && st.top() == '{') {
                    st.pop();
                } 
                else if (ch == ']' && st.top() == '[') {
                    st.pop();
                } 
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};
