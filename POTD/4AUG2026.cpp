/*
Problem: 3731. Find Missing Elements
Difficulty: Easy
Topic: Array, Sorting

Approach:
- Sort the array in ascending order.
- Traverse the sorted array while maintaining the expected value starting from the smallest element.
- If the expected value is missing, add it to the answer and continue checking.
- Otherwise, move to the next element.
- The collected values represent all missing integers in the original range.

Time Complexity: O(n log n)
Space Complexity: O(1) (excluding the output array)
*/

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int cnt = nums[0];
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (cnt != nums[i]) {
                ans.push_back(cnt);
                i--;
            }
            cnt++;
        }

        return ans;
    }
};
