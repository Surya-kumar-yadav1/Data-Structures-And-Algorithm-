//3693. Climbing Stairs II

class Solution {
    public int climbStairs(int n, int[] costs) {
        int curr=0,prev1=0,prev2=Integer.MAX_VALUE,prev3=Integer.MAX_VALUE;
        for(int i=n-1;i>=0;i--){
            int take1=take1= costs[i]+1+prev1;
            int take2=Integer.MAX_VALUE;
            if(i+1<n) take2=costs[i+1]+4+prev2;
            int take3=Integer.MAX_VALUE;
            if(i+2<n) take3=costs[i+2]+9+prev3;
            curr=Math.min(take1,Math.min(take2,take3));
            prev3=prev2;
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }
}
