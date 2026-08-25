/*
Problem: 3718. Smallest Missing Multiple of K
Difficulty: Easy
Topic: Array, Sorting, Binary Search

Approach:
- The required answer must be a positive multiple of `k`.
- Start with the smallest possible multiple:
      mul = k
- Sort the array so that we can efficiently check whether a multiple
  exists using `binary_search()`.
- Check k, 2k, 3k, ... one by one.
- As soon as we find a multiple that is not present in `nums`, return it.
- Since we are checking multiples in increasing order, the first missing
  multiple is guaranteed to be the smallest one.

Time Complexity: O(n log n + m log n)
where m is the number of multiples of k checked.

Space Complexity: O(1) excluding the sorting implementation stack.
*/

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        // Sort the array for binary search.
        sort(nums.begin(), nums.end());

        int mul = k;

        // Check multiples of k in increasing order.
        while (true) {
            if (!binary_search(nums.begin(), nums.end(), mul)) {
                return mul;
            }

            mul += k;
        }

        return 0;
    }
};
