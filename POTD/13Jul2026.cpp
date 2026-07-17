/*
Problem: 1291. Sequential Digits
Difficulty: Medium
Topic: Math, Enumeration, BFS

Approach:
- Precompute all sequential digit numbers using a BFS-like generation process.
- Start with single-digit numbers (1–9).
- Extend each number by appending the next consecutive digit whenever possible.
- Store all generated sequential numbers in ascending order.
- For each query, collect the precomputed numbers that lie within the range [low, high].

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    inline static int q[45];
    inline static bool init = []() {
        int n = 0;
        for (int i = 1; i < 10; i++)
            q[n++] = i;

        for (int i = 0; i < n; i++) {
            int d = q[i] % 10;
            if (d < 9)
                q[n++] = q[i] * 10 + d + 1;
        }

        return 0;
    }();

    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;

        for (auto &x : q)
            if (x >= low && x <= high)
                res.push_back(x);

        return res;
    }
};
