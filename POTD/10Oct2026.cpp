/*
Problem: 2333. Minimum Sum of Squared Difference
Difficulty: Medium
Topic: Array, Greedy, Counting, Bucket Sort

Approach:
- Calculate the absolute difference between corresponding elements
  of nums1 and nums2 and find the maximum difference M.
- Store the frequency of each difference in a bucket array.
- Use k = k1 + k2 as the total number of allowed operations.
- Greedily reduce the largest differences first because reducing
  larger differences gives the greatest decrease in the squared sum.
- For each difference i, move as many elements as possible from
  bucket[i] to bucket[i - 1], limited by the remaining operations.
- Finally, calculate the sum of squared differences using the
  remaining bucket frequencies.

Time Complexity: O(n + M)
Space Complexity: O(n + M)

Note:
- M is the maximum absolute difference.
- Each operation reduces one difference by 1.
- Bucket sort avoids using a priority queue and processes all
  possible difference values efficiently.
*/

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size(), M = 0;
        long long k = 1LL * k1 + k2;
        vector<int> diff(n);

        for (int i = 0; i < n; i++) {
            M = max(M, diff[i] = abs(nums1[i] - nums2[i]));
        }

        vector<int> bucket(M + 1);

        for (int x : diff) {
            bucket[x]++;
        }

        for (int i = M; i > 0 && k > 0; i--) {
            int take = min((long long)bucket[i], k);

            bucket[i] -= take;
            bucket[i - 1] += take;
            k -= take;
        }

        long long ans = 0;

        for (int i = 1; i <= M; i++) {
            ans += 1LL * bucket[i] * i * i;
        }

        return ans;
    }
};
