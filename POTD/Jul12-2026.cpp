// 2685. Count the Number of Complete Components
/*
Problem: 2685. Count the Number of Complete Components
Difficulty: Medium
Topic: Graph, DFS

Approach:
- Build an adjacency list for the graph.
- Use DFS to traverse each connected component.
- Count the number of vertices (v) and the sum of degrees (e) in the component.
- Since each undirected edge contributes twice to the degree count, a complete graph with v vertices must have a total degree of v × (v - 1).
- If e == v × (v - 1), the component is complete.

Time Complexity: O(V + E)
Space Complexity: O(V + E)
*/

class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&adj,int i,vector<int> &visited,int &v,int &e){
        visited[i]=1;
        v++;
        e+=(adj[i].size());
        for(int &it:adj[i]){
            if(!visited[it]){
                dfs(adj,it,visited,v,e);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;

        for(auto &edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(n,0);
        int result=0;

        for(int i=0;i<n;i++){
            if(visited[i]) continue;

            int v=0,e=0;
            dfs(adj,i,visited,v,e);

            if(v*(v-1)==e) result++;
        }

        return result;
    }
};