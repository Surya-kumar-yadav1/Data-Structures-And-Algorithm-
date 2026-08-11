/*
Problem: 2996. Smallest Missing Integer Greater Than Sequential Prefix Sum
Difficulty: Easy
Topics: Array, Hash Set, Simulation

Approach:
- Find the longest sequential prefix sum starting from nums[0]
- Use a hash set for O(1) lookups of existing numbers
- Starting from the prefix sum, find the smallest integer that is not in the set
- Since nums[i] ≤ 50 and n ≤ 50, the answer will be ≤ 2500

Time Complexity: O(n + m) where n is array length and m is range to search
Space Complexity: O(n) for the hash set
*/

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        // Calculate the sum of the longest sequential prefix
        int prefixSum = nums[0];
        int n = nums.size();
        
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i-1] + 1) {
                prefixSum += nums[i];
            } else {
                break;
            }
        }
        
        // Store all numbers in a hash set for O(1) lookups
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        // Find the smallest missing integer >= prefixSum
        int missing = prefixSum;
        while (numSet.count(missing)) {
            missing++;
        }
        
        return missing;
    }
};
