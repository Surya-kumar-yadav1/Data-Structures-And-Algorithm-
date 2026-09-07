/*
Problem: 940. Distinct Subsequences II
Difficulty: Hard
Topic: Dynamic Programming, String, Hashing

Approach:
- Let dp[i] represent the number of distinct subsequences, including the
  empty subsequence, that can be formed using the first i characters.
- When adding a new character, every existing subsequence can either:
    1. Exclude the new character.
    2. Include the new character.
  Therefore, the number of subsequences initially doubles:
    dp[i + 1] = 2 * dp[i]
- However, if the current character has appeared before, some subsequences
  are counted twice. Specifically, all subsequences that were formed before
  the previous occurrence of this character get duplicated.
- last[x] stores the index of the previous occurrence of character x.
- Therefore, when the character has appeared before:
    dp[i + 1] -= dp[last[x]]
- Finally, dp[N] includes the empty subsequence, so subtract 1 to count only
  non-empty distinct subsequences.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int distinctSubseqII(string s) {
        const int N = s.length();
        const int MOD = 1e9 + 7;

        vector<int> dp(N + 1);
        dp[0] = 1;

        vector<int> last(26, -1);

        for (int i = 0; i < N; i++) {
            int x = s[i] - 'a';

            dp[i + 1] = dp[i] * 2 % MOD;

            if (last[x] >= 0)
                dp[i + 1] -= dp[last[x]];

            dp[i + 1] %= MOD;

            last[x] = i;
        }

        dp[N]--;

        if (dp[N] < 0)
            dp[N] += MOD;

        return dp[N];
    }
};
