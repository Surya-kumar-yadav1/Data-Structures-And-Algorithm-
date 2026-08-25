/*
Problem: 3471. Find the Largest Almost Missing Integer
Difficulty: Easy
Topic: Array, Counting, Sliding Window

Approach:
- Count how many times each value appears in the entire array.
- An element can belong to exactly one subarray of size k in the following cases:
    1. k == n:
       There is only one subarray, so every distinct value appears in exactly
       one subarray if it exists.
    2. k == 1:
       Every position itself forms a subarray, so an integer is almost missing
       only when it occurs exactly once.
    3. k > 1 and k < n:
       A value occurring only once can belong to exactly one size-k subarray
       only when that occurrence is at either end of the array.
- Therefore, for k < n, we only consider values whose total frequency is 1
  and whose position is the first or last element.
- Keep the maximum valid value as the answer.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int largestInteger(vector<int>& A, int k) {
        int f[51] = {0};

        // Count frequency of every integer
        for (auto& x : A)
            f[x]++;

        int res = -1;
        int n = A.size();

        for (int i = 0; i < n; i++) {
            if (k == n || 
                (f[A[i]] == 1 && (k == 1 || !i || i == n - 1))) {
                res = max(res, A[i]);
            }
        }

        return res;
    }
};
