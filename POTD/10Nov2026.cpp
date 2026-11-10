//3693. Climbing Stairs II
//Time Complexity: O(n)
//Space Complexity: O(1)
//used 1D dp
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int curr=0,prev1=0,prev2=INT_MAX,prev3=INT_MAX;
        for(int i=n-1;i>=0;i--){
            int take1=take1= costs[i]+1+prev1;
            int take2=INT_MAX;
            if(i+1<n) take2=costs[i+1]+4+prev2;
            int take3=INT_MAX;
            if(i+2<n) take3=costs[i+2]+9+prev3;
            curr=min({take1,take2,take3});
            prev3=prev2;
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }
};
