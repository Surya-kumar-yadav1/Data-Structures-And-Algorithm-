/*
Problem: 3720. Lexicographically Smallest Permutation Greater Than Target
Difficulty: Medium
Topic: String, Greedy

Approach:
- Count the frequency of each character in `s`.
- Subtract the characters of `target` from the frequency array.
- Traverse `target` from right to left.
- At each position, restore the current target character to the available count.
- Check whether all remaining character counts are non-negative.
- Find the smallest available character greater than the current target character.
- If found, keep the prefix unchanged, place this larger character, and append
  all remaining characters in sorted order.
- Return the first valid result found. If no valid permutation exists, return "".

Time Complexity: O(n * 26)
Space Complexity: O(n + 26)

Note:
- We process from right to left so that the first possible change happens as
  far right as possible, making the result lexicographically smallest.
- The remaining characters are appended in sorted order to minimize the result.
*/

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int cnt[26] = {};

        for (char ch : s) {
            cnt[ch - 'a']++;
        }

        for (char ch : target) {
            cnt[ch - 'a']--;
        }

        for (int i = target.size() - 1; i >= 0; i--) {
            int cur = target[i] - 'a';
            cnt[cur]++;

            bool ok = true;

            for (int c = 0; c < 26; c++) {
                if (cnt[c] < 0) {
                    ok = false;
                    break;
                }
            }

            if (!ok)
                continue;

            int next = -1;

            for (int c = cur + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    next = c;
                    break;
                }
            }

            if (next == -1)
                continue;

            cnt[next]--;

            string ans = target.substr(0, i);
            ans += char('a' + next);

            for (int c = 0; c < 26; c++) {
                ans.append(cnt[c], char('a' + c));
            }

            return ans;
        }

        return "";
    }
};
