//3946. Maximum Number of Items From Sale I
class Solution {
public:
    int cheapest;
    map<int,int> mp;
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        cheapest=items[0][1];        
        for(int i=0;i<n;i++){
            int cnt=0,temp=items[i][0];
            cheapest=min(cheapest,items[i][1]);
            for(int j=0;j<n;j++){
                if(i!=j && items[j][0]%temp==0) cnt++;
            }
            mp[temp]=cnt;
        }
        vector<int> prev(budget+1,0),curr(budget+1,0);
        for(int i=budget;i>=0;i--) prev[i]=i/cheapest;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=budget;j++){
                int take=0,notTake=0;
                if(items[i-1][1]<=j){
                    take=1+mp[items[i-1][0]]+prev[j-items[i-1][1]];
                }
                notTake=prev[j];
                curr[j]=max(take,notTake);
            }
            prev=curr;
        }
        return prev[budget];
    }
};
