//3364. Minimum Positive Sum Subarray 
//Time Complexity:O(n^2)
//Space Complexity:O(1)
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int res=INT_MAX;
        for(int k=l;k<=r;k++){
            int sum=0;
            int low=0,high=0;
            while(high<k) sum+=nums[high++];
            if(sum>0) res=min(res,sum);
            if(high!=0) high--;
            while(high<n){
                high++;
                if(high>=n) continue;
                sum+=nums[high];
                sum-=nums[low];
                low++;         
                if(sum>0) res=min(res,sum);     
            }
        }
        if(res!=INT_MAX) return res;
        return -1;
    }
};
