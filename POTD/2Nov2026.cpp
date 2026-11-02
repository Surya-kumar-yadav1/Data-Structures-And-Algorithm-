//462. Minimum Moves to Equal Array Elements II
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size(),res=0;
        int mid=n/2;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i==mid) continue;
            res+=abs(nums[i]-nums[mid]);
        }
        return res;
    }
};
