 /*
 Problem: 3116. Kth Smallest Amount With Single Denomination Combination
 Difficulty: Hard
 Topic: Number Theory, Inclusion-Exclusion, LCM, Binary Search, Bit Manipulation

 Approach:
 - First sort the coin denominations.
 - Remove any coin that is a multiple of another smaller coin because every
   amount obtainable from that coin is already obtainable using the smaller
   denomination.
 - For a value `mid`, count how many positive amounts <= mid can be formed.
 - An amount is valid if it is divisible by at least one remaining coin.
 - Use the Inclusion-Exclusion Principle over all subsets of coins:
     * For an odd-sized subset, add the count of multiples of its LCM.
     * For an even-sized subset, subtract the count.
 - `mid / LCM` gives the number of multiples of that LCM not exceeding `mid`.
 - The `check(mid)` function tells whether at least `k` valid amounts exist.
 - Since the number of valid amounts increases monotonically with `mid`,
   binary search can find the smallest value having at least `k` amounts.
 - The expression
       q = (((r ^ q) >> 2) / c) | r;
   generates the next subset of the same size efficiently using Gosper's
   combination generation technique.

Time Complexity: O(2^n * n * log(A[0] * k))
Space Complexity: O(n)
*/

class Solution {
public:
    using ll = long long;

    long long findKthSmallest(vector<int>& coins, int k) {
        // Sort the denominations.
        ranges::sort(coins);

        vector<int> A;

        // Remove redundant denominations.
        // If c is divisible by an already kept coin x, every multiple of c
        // is also a multiple of x, so c adds nothing new.
        for (auto& c : coins)
            if (ranges::none_of(A, [&](int x) {
                    return !(c % x);
                }))
                A.push_back(c);

        int n = A.size();

        // check(mid) = whether at least k valid amounts <= mid exist.
        auto check = [&](ll mid) {
            ll tot = 0;

            // Consider subsets of every possible size.
            for (int i = 1; i <= n; i++) {
                // Smallest subset having exactly i bits set.
                int q = (1 << i) - 1;

                // Generate all subsets of size i.
                while (q < 1 << n) {
                    ll x = 1;

                    // Calculate the LCM of all coins in this subset.
                    for (int j = 0; j < n; j++)
                        if ((q >> j) & 1)
                            x = lcm(x, A[j]);

                    // Inclusion-Exclusion:
                    // odd subset -> add
                    // even subset -> subtract
                    tot += (mid / x) * (((i & 1) << 1) - 1);

                    // Generate the next combination with i set bits.
                    int c = q & -q;
                    int r = q + c;
                    q = (((r ^ q) >> 2) / c) | r;
                }
            }

            return tot >= k;
        };

        // The kth amount is at least k because every positive amount
        // contributes at most one new valid value.
        ll low = k;

        // Using the smallest denomination, its first k multiples give
        // a valid upper bound.
        ll high = 1LL * A[0] * k;

        // Find the smallest mid for which check(mid) is true.
        return *ranges::lower_bound(
            views::iota(low, high + 1),
            true,
            {},
            [&](ll mid) {
                return check(mid);
            }
        );
    }
};
