/*
Problem: 3867. Sum of GCD of Formed Pairs
Difficulty: Medium
Topic: Array, Math, GCD, Sorting

Approach:
- Traverse the array while maintaining the maximum element seen so far.
- Replace each element with gcd(nums[i], currentMax) to construct the prefixGcd array.
- Sort the prefixGcd array in non-decreasing order.
- Pair the smallest and largest remaining elements, then add their GCD to the answer.
- If the array has an odd length, the middle element is left unpaired.

Time Complexity: O(n log n)
Space Complexity: O(1) (excluding the sorting algorithm's internal space)
*/

class Solution {
public:
    long long gcdSum(vector<int>& A) {
        int max = 0;

        for (auto& n : A) {
            max = ::max(max, n);
            n = gcd(n, max);
        }

        ranges::sort(A);

        long long res = 0;
        for (int i = 0, j = A.size() - 1; i < j; i++, j--) {
            res += gcd(A[i], A[j]);
        }

        return res;
    }
};
