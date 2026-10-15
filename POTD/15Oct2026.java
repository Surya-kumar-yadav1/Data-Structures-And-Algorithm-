/*
Problem: 2913. Subarrays Distinct Element Sum of Squares I
Difficulty: Easy
Topic: Array, Hash Table, Enumeration

Approach: Brute Force + Frequency Array

1. Fix the starting index i of each subarray.
2. Create a frequency array of size 101 to track occurrences.
3. Extend the subarray by moving j from i to n - 1.
4. If freq[nums.get(j)] == 0, the element has not appeared
   before, so increment the distinct count.
5. Add distinct * distinct to the answer for every subarray.
6. Return the final answer.

Time Complexity: O(n^2)
Space Complexity: O(1), because the frequency array has
a fixed size of 101.
*/

class Solution {
    public int sumCounts(List<Integer> nums) {
        int ans = 0;
        int n = nums.size();

        // Fix the starting index of each subarray
        for (int i = 0; i < n; i++) {

            // Store the frequency of each element
            int[] freq = new int[101];

            // Count distinct elements in the current subarray
            int distinct = 0;

            // Extend the subarray by moving the ending index
            for (int j = i; j < n; j++) {

                // If the element appears for the first time,
                // increment the distinct element count
                if (freq[nums.get(j)] == 0) {
                    distinct++;
                }

                // Update the frequency of the current element
                freq[nums.get(j)]++;

                // Add the square of the distinct count
                ans += distinct * distinct;
            }
        }

        // Return the sum for all possible subarrays
        return ans;
    }
}
