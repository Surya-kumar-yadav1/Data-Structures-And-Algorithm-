/*
Problem: 1331. Rank Transform of an Array
Difficulty: Easy
Topic: Array, Sorting, Hash Map

Approach:
- Create a copy of the original array and sort it.
- Assign ranks to unique elements in increasing order using a hash map.
- Replace each element in the original array with its corresponding rank.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        int n = arr.size();
        unordered_map<int, int> mp;

        sort(temp.begin(), temp.end());

        int cnt = 1;
        for (int i = 0; i < n; i++) {
            if (mp.find(temp[i]) == mp.end())
                mp[temp[i]] = cnt++;
        }

        for (int &x : arr) {
            x = mp[x];
        }

        return arr;
    }
};