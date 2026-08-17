
/*
Problem: 2958. Length of Longest Subarray With at Most K Frequency
Difficulty: Medium
Topic: Array, Hash Map, Sliding Window

Approach:
- Use a sliding window with two pointers, l and r.
- Store the frequency of each element in the current window using an
  unordered_map.
- Expand the window by moving r and increase the frequency of nums[r].
- If the frequency of the newly added element becomes greater than k,
  move l forward and decrease the frequencies until the window becomes valid.
- At every step, update the maximum length of the valid window.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        const int n = nums.size();
        int cnt = 0;

        unordered_map<int, int> freq;
        freq.reserve(n);

        for (int l = 0, r = 0; r < n; r++) {
            int x = nums[r];

            auto it = freq.find(x);
            int& f = (it == freq.end()) ? freq[x] = 1 : ++(it->second);

            while (f > k)
                freq[nums[l++]]--;

            cnt = max(cnt, r - l + 1);
        }

        return cnt;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
```
