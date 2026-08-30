/*
Problem: 2948. Make Lexicographically Smallest Array by Swapping Elements
Difficulty: Medium
Topic: Array, Sorting, Greedy

Approach:
- Create a sorted copy of the array.
- In the sorted array, divide elements into groups.
- Two consecutive elements belong to the same group if their difference is
  at most `limit`.
- Elements from the same group can be rearranged among their original
  positions through a sequence of valid swaps.
- Store the group number of each value.
- For every element in the original array, replace it with the smallest
  unused value from its corresponding group.
- This produces the lexicographically smallest obtainable array.

Time Complexity: O(n log n)
Space Complexity: O(n)

Note:
- Sorting takes O(n log n), while grouping and reconstructing the result
  take O(n).
- The `unordered_map` is used to find the group of each value efficiently.
- Duplicate values are handled correctly because the group index is tracked
  using `idx`.
*/

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& A, int limit) {
        vector<int> sorted = A;
        ranges::sort(sorted);

        vector<vector<int>> grps;
        unordered_map<int, int> map;

        int id = -1;

        for (int i = 0; i < sorted.size(); i++) {
            if (i == 0 || sorted[i] - sorted[i - 1] > limit) {
                grps.push_back({});
                id++;
            }

            grps[id].push_back(sorted[i]);
            map[sorted[i]] = id;
        }

        vector<int> idx(grps.size(), 0);

        for (int i = 0; i < A.size(); i++) {
            int cur = map[A[i]];

            A[i] = grps[cur][idx[cur]];
            idx[cur]++;
        }

        return A;
    }
};
