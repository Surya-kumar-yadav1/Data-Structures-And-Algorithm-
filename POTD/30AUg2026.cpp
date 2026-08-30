/*
Problem: 2091. Removing Minimum and Maximum From Array
Difficulty: Medium
Topic: Array, Greedy

Approach:
- Find the indices of the minimum and maximum elements.
- There are three possible ways to remove both elements:
  1. Remove both from the front and back.
  2. Remove the leftmost element from the front and the rightmost element
     from the back by first removing everything up to the right position.
  3. Remove both from the front, or equivalently handle the elements from
     the back.
- Calculate the number of deletions for each possible strategy.
- Return the minimum among the three values.

Time Complexity: O(n)
Space Complexity: O(1)

Note:
- `min_element()` and `max_element()` find the positions of the minimum and
  maximum elements in O(n).
- Since deletions can only happen from the two ends, considering these three
  strategies is sufficient to find the minimum number of deletions.
*/

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxIdx = max_element(nums.begin(), nums.end()) - nums.begin();

        // Remove one element from the front and the other from the back
        int ans1 = minIdx < maxIdx
                    ? minIdx + 1 + n - maxIdx
                    : maxIdx + 1 + n - minIdx;

        // Remove both elements from the front
        int ans2 = abs(minIdx - maxIdx) + 1 + min(minIdx, maxIdx);

        // Remove both elements from the back
        int ans3 = n - max(minIdx, maxIdx) + abs(minIdx - maxIdx);

        return min({ans1, ans2, ans3});
    }
};
