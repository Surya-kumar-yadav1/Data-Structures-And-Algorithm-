/*
Problem: 3302. Find the Lexicographically Smallest Valid Sequence
Difficulty: Medium
Topic: String, Greedy, Two Pointers

Approach:
- Traverse word1 from right to left and store the latest possible index
  for matching each character of word2.
- Traverse word1 from left to right and greedily construct the answer.
- If the current character matches word2[j], select it.
- Otherwise, use the one allowed character change if enough characters
  remain to complete word2.
- By always choosing the earliest possible index, we obtain the
  lexicographically smallest valid sequence.

Time Complexity: O(n + m)
Space Complexity: O(m)
*/

class Solution {
    public List<Integer> validSequence(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();

        int[] last = new int[m];
        Arrays.fill(last, -1);

        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {
            if (word1.charAt(i) == word2.charAt(j)) {
                last[j] = i;
                j--;
            }
            i--;
        }

        List<Integer> ans = new ArrayList<>();
        boolean canSkip = true;
        j = 0;

        for (i = 0; i < n && j < m; i++) {
            if (word1.charAt(i) == word2.charAt(j)) {
                ans.add(i);
                j++;
            }
            else if (canSkip &&
                     (j == m - 1 || i < last[j + 1])) {
                canSkip = false;
                ans.add(i);
                j++;
            }
        }

        if (j == m)
            return ans;

        return new ArrayList<>();
    }
}
