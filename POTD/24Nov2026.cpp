//3411. Maximum Subarray With Equal Products
class Solution {
public:
    int maxLength(vector<int>& nums) {
        long long res=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            long long len=1;
            int prod=nums[i],gc=nums[i],lc=nums[i];
            for(int j=i+1;j<n;j++){
                prod*=(nums[j]*1LL);
                gc=__gcd(gc,nums[j]);
                lc=lcm(lc,nums[j]);
                len++;
                if(prod==gc*lc) res=max(res,len);
            }
        }
        return res;
    }
};
