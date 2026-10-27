//3619. Count Islands With Total Value Divisible by K
class Solution {
public:
    using ll=long long;
    int n,m;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    ll bfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& vis){
        ll sum=0;
        vis[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto [x,y]=q.front();
                q.pop();
                sum+=grid[x][y];
                for(int k=0;k<4;k++){
                    int row=x+dx[k],col=y+dy[k];
                    if(row>=0 && col>=0 && row<n && col<m && !vis[row][col] && grid[row][col]!=0){
                        q.push({row,col});
                        vis[row][col]=1;
                    }
                }
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        n=grid.size(),m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0 && !vis[i][j]){
                    ll sum=bfs(i,j,grid,vis);
                    if(sum%k==0) {cnt++;}
                }
            }
        }
        return cnt;
    }
};
