//3105. Longest Strictly Increasing or Strictly Decreasing Subarray
//Time Complexity : O(n)
//Space Complexity : O(1)
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int res=1,inc=1,dec=1;
        for(int i=1;i<n;i++){
            dec=nums[i-1]>nums[i]?++dec:1;
            inc=nums[i-1]<nums[i]?++inc:1;
            res=max({dec,inc,res});
        }
        return res;
    }
};
