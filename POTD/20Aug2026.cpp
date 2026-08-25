/*
Problem: 3069. Distribute Elements Into Two Arrays I
Difficulty: Easy
Topic: Array, Simulation

Approach:
- Initialize arr1 with nums[0] and arr2 with nums[1] as required.
- For every remaining element:
    - Compare the last elements of arr1 and arr2.
    - If arr1's last element is greater, append the current element to arr1.
    - Otherwise, append it to arr2.
- Finally, concatenate arr2 at the end of arr1 to form the result.
- The expression:
      A[A[0].back() <= A[1].back()]
  works because:
      - If arr1.back() <= arr2.back(), index 1 is selected, so the element
        goes to arr2.
      - Otherwise, index 0 is selected, so the element goes to arr1.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> A[2] = {{nums[0]}, {nums[1]}};

        const int n = nums.size();

        // Distribute the remaining elements.
        for (int i = 2; i < n; i++) {
            A[A[0].back() <= A[1].back()].push_back(nums[i]);
        }

        // Concatenate arr2 to arr1.
        A[0].insert(A[0].end(), A[1].begin(), A[1].end());

        return A[0];
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
