/*
Problem: 3312. Sorted GCD Pair Queries
Difficulty: Hard
Topic: Math, Number Theory, Binary Search, Prefix Sum

Approach:
- Count the frequency of each number in the array.
- Iterate from the largest possible GCD down to 1.
- For each value i, count how many array elements are divisible by i.
- Compute the number of pairs with GCD exactly i using the Inclusion-Exclusion principle by subtracting pairs already counted for multiples of i.
- Build a prefix sum array where prefix[i] stores the number of pairs with GCD ≤ i.
- For each query, use binary search (upper_bound) on the prefix sum array to find the smallest GCD whose cumulative pair count exceeds the query index.

Time Complexity: O(M log M + Q log M)
Space Complexity: O(M)

Where:
- M = maximum value in nums
- Q = number of queries
*/

class Solution {
    using ll = long long;
public:
    vector<int> gcdValues(vector<int>& A, vector<long long>& queries) {
        int mx = ranges::max(A);
        vector<int> freq(mx + 1, 0);
        vector<ll> GCD(mx + 1, 0);

        for (auto &a : A)
            freq[a]++;

        for (int i = mx; i > 0; i--) {
            ll sm = 0, extra = 0;

            for (int j = i; j <= mx; j += i) {
                sm += freq[j];
                extra += GCD[j];
            }

            GCD[i] = sm * (sm - 1) / 2 - extra;
        }

        partial_sum(GCD.begin(), GCD.end(), GCD.begin());

        vector<int> res(queries.size());

        for (int i = 0; i < queries.size(); i++)
            res[i] = ranges::upper_bound(GCD, queries[i]) - GCD.begin();

        return res;
    }
};
