/*
Problem: 3734. Lexicographically Smallest Palindromic Permutation Greater Than Target
Difficulty: Hard
Topic: String, Greedy, Frequency Array

Approach:
- Count the frequency of each character in `s`.
- A palindrome can have at most one character with an odd frequency.
  If more than one exists, return an empty string.
- Since the palindrome is symmetric, only construct its first half.
- Subtract the characters required by the first half of `target` from the
  available frequencies.
- First, check whether the first half of `target` itself can be formed.
  If yes, construct the corresponding palindrome and check whether it is
  strictly greater than `target`.
- If that does not work, traverse the first half of `target` from right to left.
- At each position, restore the required character and try to place the
  smallest character greater than it.
- After making the first larger choice, place all remaining characters in
  sorted order to obtain the lexicographically smallest possible palindrome.
- Return the first valid palindrome found.

Time Complexity: O(n + 26²)
Space Complexity: O(n + 26)

Note:
- Only half of the palindrome needs to be constructed because the other half
  is completely determined by symmetry.
- Processing from right to left allows us to make the first increase as late
  as possible, which gives the smallest lexicographic result.
- The `check()` function verifies whether the required character frequencies
  are available.
*/

class Solution {
public:
    string lexPalindromicPermutation(string str, string target) {
        int freq[26] = {0};

        for (char s : str)
            freq[s - 'a']++;

        char center = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                if (center != 0)
                    return "";

                center = 'a' + i;
                freq[i]--;
            }
        }

        int sz = str.length();
        int half = sz / 2;

        for (int i = 0; i < half; i++)
            freq[target[i] - 'a'] -= 2;

        // Check if target's first half can be used directly
        if (check(freq)) {
            string head = target.substr(0, half);
            string rev = head;
            reverse(rev.begin(), rev.end());

            string tail = "";

            if (center != 0)
                tail += center;

            tail += rev;

            if (tail > target.substr(half))
                return head + tail;
        }

        // Find the rightmost position where we can make the palindrome larger
        for (int i = half - 1; i >= 0; i--) {
            char w = target[i];
            freq[w - 'a'] += 2;

            if (!check(freq))
                continue;

            // Try the smallest character greater than target[i]
            for (int j = (w - 'a') + 1; j < 26; j++) {
                if (freq[j] == 0)
                    continue;

                freq[j] -= 2;

                string result = target.substr(0, i + 1);
                result[i] = 'a' + j;

                // Fill the remaining first half in sorted order
                for (int k = 0; k < 26; k++) {
                    int cnt = freq[k] / 2;

                    if (cnt > 0)
                        result.append(cnt, 'a' + k);
                }

                // Construct the second half by mirroring the first half
                string part = result;
                reverse(part.begin(), part.end());

                if (center != 0)
                    result.push_back(center);

                result += part;

                return result;
            }
        }

        return "";
    }

    bool check(int f[]) {
        for (int i = 0; i < 26; i++) {
            if (f[i] < 0)
                return false;
        }

        return true;
    }
};
