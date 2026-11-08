//1267. Count Servers that Communicate
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int> row(n),col(m);
        int total=0;
        for(int i=0;i<n;i++){
            int rowcnt=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) {
                    row[i]++;
                    col[j]++;
                    total++;
                }
            }
        }
        int noComm=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && row[i]==1 && col[j]==1) {
                    noComm++;
                }
            }
        }
        return abs(total-noComm);
    }
};
