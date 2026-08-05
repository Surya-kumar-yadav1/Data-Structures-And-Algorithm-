```cpp id="t9m4qx"
/*
Problem: 3310. Remove Methods From Project
Difficulty: Medium
Topic: Graph, DFS

Approach:
- Build a directed graph representing method invocations.
- Perform a DFS starting from the buggy method k to mark all suspicious methods.
- Check whether any non-suspicious method invokes a suspicious method.
- If such an invocation exists, the suspicious group cannot be removed, so return all methods.
- Otherwise, return only the methods that are not marked as suspicious.

Time Complexity: O(n + m)
Space Complexity: O(n + m)

Where:
- n = number of methods
- m = number of invocations
*/

class Solution {
public:
    void dfs(vector<vector<int>>& adjList, int node, vector<int>& visited) {
        visited[node] = 1;

        for (int& nbr : adjList[node]) {
            if (!visited[nbr])
                dfs(adjList, nbr, visited);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        int m = invocations.size();
        vector<vector<int>> adjList(n);
        vector<int> ans;

        for (int i = 0; i < m; i++) {
            int u = invocations[i][0];
            int v = invocations[i][1];
            adjList[u].push_back(v);
        }

        vector<int> visited(n, 0);
        dfs(adjList, k, visited);

        for (int i = 0; i < m; i++) {
            int u = invocations[i][0];
            int v = invocations[i][1];

            if (visited[u] == 0 && visited[v] == 1) {
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0)
                ans.push_back(i);
        }

        return ans;
    }
};
```
