/* 
Problem: 3524. Find X Value of Array I
Difficulty: Medium
Topic: Array, Dynamic Programming, Modular Arithmetic

Approach:
- We need to count all non-empty subarrays of nums.
- For every position, keep `freq[r]`, which represents how many
  subarrays ending at the previous position have product remainder
  `r` modulo k.
- For the current element with remainder `r`:
  - Start a new subarray containing only the current element.
    Its product remainder is `r`, so increase `ans[r]`.
  - Extend every previous subarray by the current element.
    If its old remainder is `j`, the new remainder becomes
    `(j * r) % k`.
    Add its count to both `freq2` and `ans`.
  - Finally, add the current element itself into `freq2`.
- Replace `freq` with `freq2` and continue.
- `ans[x]` therefore stores the number of subarrays whose product
  leaves remainder `x` modulo k.
- Special case: when `k == 1`, every subarray has remainder 0.
  The number of non-empty subarrays is `n * (n + 1) / 2`.

Time Complexity: O(n * k)
Space Complexity: O(k)
*/

int freq[5], freq2[5];

class Solution {
public:
    static vector<long long> resultArray(vector<int>& nums, int k) {
        const int n = nums.size();

        // Special case: every product % 1 = 0
        if (k == 1)
            return {1LL * n * (n + 1) / 2};

        vector<long long> ans(k, 0);

        // freq[r] = number of subarrays ending at previous index
        // whose product % k == r
        memset(freq, 0, sizeof(int) * k);

        for (int x : nums) {
            const int r = x % k;

            // Reset for subarrays ending at current index
            memset(freq2, 0, sizeof(int) * k);

            // Start a new subarray with only x
            ans[r]++;

            // Extend all previous subarrays with x
            for (int j = 0; j < k; j++) {
                const int prod = j * r % k;

                freq2[prod] += freq[j];
                ans[prod] += freq[j];
            }

            // Add the single-element subarray [x]
            freq2[r]++;

            // Move current frequencies to freq
            memcpy(freq, freq2, sizeof(int) * k);
        }

        return ans;
    }
};
