```python
"""
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
"""

class Solution:
    def dfs(self, adjList, node, visited):
        visited[node] = True

        for nbr in adjList[node]:
            if not visited[nbr]:
                self.dfs(adjList, nbr, visited)

    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        adjList = [[] for _ in range(n)]

        for u, v in invocations:
            adjList[u].append(v)

        visited = [False] * n
        self.dfs(adjList, k, visited)

        for u, v in invocations:
            if not visited[u] and visited[v]:
                return list(range(n))

        return [i for i in range(n) if not visited[i]]
```
