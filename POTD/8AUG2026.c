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

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int* validSequence(char* word1, char* word2, int* returnSize) {
    int n = strlen(word1);
    int m = strlen(word2);

    int* last = (int*)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++)
        last[i] = -1;

    int i = n - 1;
    int j = m - 1;

    while (i >= 0 && j >= 0) {
        if (word1[i] == word2[j]) {
            last[j] = i;
            j--;
        }

        i--;
    }

    int* ans = (int*)malloc(m * sizeof(int));
    *returnSize = 0;

    bool canSkip = true;
    j = 0;

    for (i = 0; i < n && j < m; i++) {
        if (word1[i] == word2[j]) {
            ans[(*returnSize)++] = i;
            j++;
        }
        else if (canSkip &&
                 (j == m - 1 || i < last[j + 1])) {
            canSkip = false;
            ans[(*returnSize)++] = i;
            j++;
        }
    }

    free(last);

    if (j == m)
        return ans;

    free(ans);
    *returnSize = 0;

    return NULL;
}
