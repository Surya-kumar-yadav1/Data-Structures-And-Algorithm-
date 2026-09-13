/*
Problem: 3414. Maximum Score of Non-overlapping Intervals
Difficulty: Hard
Topic: Dynamic Programming, Binary Search, Sorting, Lexicographical Order

Approach:
- Sort the intervals by their ending position.
- Let order contain the original indices of the intervals in sorted order.
- For each interval, use binary search to find the first interval whose
  ending position is >= its starting position. Since intervals sharing a
  boundary are considered overlapping, we need intervals with:
    previousRight < currentLeft
- Use DP where prev[p] stores the best result using at most the already
  processed intervals and the current number of selected intervals.
- For every interval, we have two choices:
    1. Skip the interval.
    2. Take the interval and combine it with the best valid previous state.
- We store the score as negative so that using min() automatically selects
  the larger score.
- When scores are equal, comparing the sorted vectors of indices gives the
  lexicographically smaller answer.
- Repeat the DP for 4 selections because we can choose at most 4 intervals.
- Each selected index is inserted into the answer vector in sorted order so
  that vector comparison directly gives lexicographical order.

Time Complexity: O(4 * n * (log n + 4)) = O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<int> order(n);
        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(), [&](int a, int b) {
            return intervals[a][1] < intervals[b][1];
        });

        vector<int> rights(n);

        for (int p = 0; p < n; p++)
            rights[p] = intervals[order[p]][1];

        using State = pair<long long, vector<int>>;

        vector<State> prev(n + 1, {0, {}});

        for (int k = 0; k < 4; k++) {
            vector<State> cur(n + 1, {0, {}});

            for (int p = 1; p <= n; p++) {
                int i = order[p - 1];

                int l = intervals[i][0];
                int w = intervals[i][2];

                int j = lower_bound(
                    rights.begin(),
                    rights.end(),
                    l
                ) - rights.begin();

                State take = prev[j];

                take.first -= w;

                take.second.insert(
                    upper_bound(
                        take.second.begin(),
                        take.second.end(),
                        i
                    ),
                    i
                );

                cur[p] = min(take, cur[p - 1]);
            }

            prev = move(cur);
        }

        return prev[n].second;
    }
};
