//3863. Minimum Operations to Sort a String
/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        char mini = s[0], maxi = s[0];

        for (char &c : s) {
            maxi = max(maxi, c);
            mini = min(mini, c);
        }

        if (is_sorted(s.begin(), s.end())) return 0;
        if (n == 1) return 0;
        if (n == 2) return -1;

        if (s[0] == mini || s[n - 1] == maxi) return 1;
        else if (s[0] == maxi && s[n - 1] == mini) {
            int minIdx = s.find(mini, 1);
            int maxIdx = s.find(maxi, 1);

            if ((minIdx > 0 && minIdx < n - 1) ||
                (maxIdx > 0 && maxIdx < n - 1)) {
                return 2;
            }

            return 3;
        }

        return 2;
    }
};
