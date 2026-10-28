//3882. Minimum XOR Path in a Grid
class Solution {
public:
    int n,m;
    int fun(int i,int j,int xorVal,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        xorVal^=grid[i][j];
        if(i==n-1 && j==m-1) return xorVal;
        if(dp[i][j][xorVal]!=-1) return dp[i][j][xorVal];
        int ans=INT_MAX;
        if(j+1<m){
            ans=min(ans,fun(i,j+1,xorVal,grid,dp));
        }
        if(i+1<n){
            ans=min(ans,fun(i+1,j,xorVal,grid,dp));
        }
        return dp[i][j][xorVal]=ans;
    }
    int minCost(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(1024,-1)));
        return fun(0,0,0,grid,dp);
    }
};
