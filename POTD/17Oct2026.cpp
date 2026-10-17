//3551. Minimum Swaps to Sort by Digit Sum
int digit(int n){
    int sum=0;
    while(n>0){
        sum+=(n%10);
        n/=10;
    }
    return sum;
}
struct cmp{
    bool operator()(int &a,int &b){
        int na=digit(a),nb=digit(b);
        if(na!=nb) return na<nb;
        return a<b;
    }
};
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp=nums;
        sort(temp.begin(),temp.end(),cmp());
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){ mp[nums[i]]=i; }
        int res=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=temp[i]){
                res++;
                int in=nums[i],it=temp[i];
                int ti=mp[temp[i]],ni=mp[nums[i]];
                swap(nums[i],nums[mp[temp[i]]]);
                mp[in]=ti,mp[it]=in;
            }
        }
        return res;
    }
};
