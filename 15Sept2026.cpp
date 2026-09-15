/* 
Problem: 2472. Maximum Number of Non-overlapping Palindrome Substrings
Difficulty: Hard
Topic: Dynamic Programming, String, Palindrome 
 
Approach: 
- First, precompute whether every substring is a palindrome. 
- Use isPalindrome[left][right] to store whether s[left...right] is a palindrome. 
- A substring is a palindrome if: 
    s[left] == s[right] 
    and the inside substring is also a palindrome. 
- Then use DP where dp[i] represents the maximum number of 
  non-overlapping palindromic substrings that can be selected 
  from the first i characters. 
- For every position i, there are two choices: 
    1. Skip s[i-1], so dp[i] = dp[i-1]. 
    2. Take a palindrome ending at i-1 with length >= k. 
- If s[j...i-1] is a palindrome and its length is at least k, 
  then we can take it and update: 
    dp[i] = max(dp[i], dp[j] + 1) 
- Since the previous chosen substrings end before j, the selected 
  substrings never overlap. 
- Finally, dp[n] gives the maximum number of non-overlapping 
  palindromic substrings. 
 
Time Complexity: O(n^2) 
Space Complexity: O(n^2) 
*/ 

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<vector<bool>> isPalindrome(
            n, vector<bool>(n)
        );

        for (int len = 1; len <= n; ++len) {
            for (int left = 0; left + len <= n; ++left) {
                int right = left + len - 1;

                isPalindrome[left][right] =
                    s[left] == s[right] &&
                    (len <= 2 || isPalindrome[left + 1][right - 1]);
            }
        }

        vector<int> dp(n + 1);

        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];

            for (int j = 0; j + k <= i; ++j) {
                if (isPalindrome[j][i - 1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};
