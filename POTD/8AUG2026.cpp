/*
Problem: 3302. Find the Lexicographically Smallest Valid Sequence
Difficulty: Medium
Topic: String, Greedy, Two Pointers

Approach:
- Traverse word1 from right to left and store the latest possible index
  for matching each character of word2.
- Then traverse word1 from left to right to construct the answer greedily.
- If the current character matches word2[j], select it.
- Otherwise, we can use our one allowed character change if selecting the
  current index still leaves enough characters to complete word2.
- The condition i < last[j + 1] ensures that the remaining characters
  can still be matched after using the current index as the changed character.
- Since we always choose the earliest possible index, the resulting
  sequence is lexicographically smallest.

Time Complexity: O(n + m)
Space Complexity: O(m)
*/

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> last(m, -1);

        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                --j;
            }

            --i;
        }

        vector<int> ans;
        ans.reserve(m);

        bool canSkip = true;
        j = 0;

        for (i = 0; i < n && j < m; ++i) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                ++j;
            }
            else if (canSkip &&
                     (j == m - 1 || i < last[j + 1])) {
                canSkip = false;
                ans.push_back(i);
                ++j;
            }
        }

        if (j == m)
            return ans;

        return {};
    }
};
