```cpp
/*
Problem: 3090. Maximum Length Substring With Two Occurrences
Difficulty: Easy
Topic: String, Hash Map, Sliding Window

Approach:
- Use a sliding window with two pointers, low and high.
- Store the frequency of each character in the current window using
  an unordered_map.
- Expand the window by moving high and increase the frequency of s[high].
- If any character occurs more than two times, move low forward and
  decrease the frequency of characters until the window becomes valid.
- At every step, update the maximum length of the valid substring.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxLen = INT_MIN;
        unordered_map<char, int> mp;

        int n = s.size();
        int low = 0;

        for (int high = 0; high < n; high++) {
            mp[s[high]]++;

            while (mp[s[high]] > 2) {
                mp[s[low]]--;

                if (mp[s[low]] == 0)
                    mp.erase(s[low]);

                low++;
            }

            maxLen = max(maxLen, high - low + 1);
        }

        return maxLen;
    }
};
```
