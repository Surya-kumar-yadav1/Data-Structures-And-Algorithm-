/* 
Problem: 3904. Smallest Stable Index II 
Difficulty: Medium 
Topic: Array, Greedy, Prefix Maximum 
 
Approach: 
- Maintain maxSoFar, the maximum value seen from index 0 to the current index. 
- cand represents the smallest index that can still be stable. 
- cMax stores the prefix maximum at the current candidate index. 
- For every index i, if nums[i] < cMax - k, then the current candidate 
  cannot be stable because the suffix minimum at i is too small. 
- Therefore, move the candidate to i + 1 and continue checking. 
- At the end, if cand is within the array, it is the smallest stable index. 
  Otherwise, return -1. 
 
Time Complexity: O(n) 
Space Complexity: O(1) 
*/ 
 
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxSoFar = -1;
        int cand = 0, cMax = 0;

        for (int i = 0; i < nums.size(); i++) {
            maxSoFar = max(maxSoFar, nums[i]);

            if (i == cand)
                cMax = maxSoFar;

            if (nums[i] < cMax - k)
                cand = i + 1;
        }

        return cand < nums.size() ? cand : -1;
    }
};
