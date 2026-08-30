/*
Problem: 2904. Shortest and Lexicographically Smallest Beautiful String
Difficulty: Medium
Topic: String

Approach:
- Consider every possible starting position of the substring.
- Extend the substring character by character while counting the number of '1's.
- If the count becomes greater than k, stop because the substring can no longer be beautiful.
- Whenever the count becomes exactly k, compare the current substring with the answer.
- Update the answer if the current substring is shorter, or if both have the same length and the current one is lexicographically smaller.
- Return the best substring found. If no beautiful substring exists, return an empty string.

Time Complexity: O(n²)
Space Complexity: O(n)

Note:
- We stop early when the number of '1's exceeds k, which avoids unnecessary checks.
- `cur < ans` is used to compare strings lexicographically.
*/

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int oneCnt = 0;
            string cur = "";

            for (int j = i; j < n; j++) {
                cur += s[j];

                if (s[j] == '1')
                    oneCnt++;

                // More than k ones can never become valid again
                if (oneCnt > k)
                    break;

                if (oneCnt == k) {
                    if (ans == "" ||
                        cur.size() < ans.size() ||
                        (cur.size() == ans.size() && cur < ans)) {
                        ans = cur;
                    }
                }
            }
        }

        return ans;
    }
};
