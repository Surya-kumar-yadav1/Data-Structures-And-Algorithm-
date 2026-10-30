//3970. Shortest Path With At Most K Consecutive Identical Characters
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        using T=tuple<int,int,int>;
        vector<vector<pair<int,int>>> graph(n);
        for(auto &it:edges){
            int u=it[0],v=it[1],w=it[2];
            graph[u].push_back({v,w});
        }
        vector<vector<int>> dist(n,vector<int>(k+1,INT_MAX));
        int src=0;
        dist[src][1]=0;
        priority_queue<T,vector<T>,greater<T>> pq;
        pq.push({0,1,src});
        while(!pq.empty()){
            auto [dst,cnt,node]=pq.top();
            pq.pop();
            if(dst!=dist[node][cnt]) continue;
            if(node==n-1) return dst;
            for(auto &nbr:graph[node]){
                int adj=nbr.first,wt=nbr.second;
                int val=(labels[adj]==labels[node])?cnt+1:1;
                if(val>k) continue;
                long long totDis=dst+wt;
                if(dist[adj][val]>totDis){
                    dist[adj][val]=totDis;
                    pq.push({dist[adj][val],val,adj});
                }
            }
        }
        int mini=*min_element(dist[n-1].begin(),dist[n-1].end());
        if(mini==INT_MAX) return -1;
        return mini;
    }
};
//
