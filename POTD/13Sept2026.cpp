/*
Problem: 835. Image Overlap
Difficulty: Medium
Topic: Array, Hash Map, Geometry

Approach:
- Store the coordinates of all 1s in both images.
- Consider one 1-bit from img1 and one 1-bit from img2.
- For these two bits to overlap, img1's bit must be translated by:
    dx = row2 - row1
    dy = col2 - col1
- Therefore, every pair of 1-bits represents one possible translation.
- Store the frequency of each translation (dx, dy) in a map.
- If multiple pairs produce the same translation, all those pairs overlap
  simultaneously after applying that translation.
- Hence, the maximum frequency of any translation is the largest possible
  overlap.

Time Complexity: O(n^4)
Space Complexity: O(n^2)
*/

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int>> A, B;
        int n = img1.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1)
                    A.push_back({i, j});

                if (img2[i][j] == 1)
                    B.push_back({i, j});
            }
        }

        map<pair<int, int>, int> mp;

        for (auto &[row1, col1] : A) {
            for (auto &[row2, col2] : B) {
                int dx = row2 - row1;
                int dy = col2 - col1;

                mp[{dx, dy}]++;
            }
        }

        int res = 0;

        for (auto &it : mp)
            res = max(res, it.second);

        return res;
    }
};
