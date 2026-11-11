//3789. Minimum Cost to Acquire Required Items

//Time Complexity : O(1)
//Space Complexity : O(1)
class Solution {
public:
    using ll=long long;
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll val=((need1*1LL)*cost1);
        ll vav=(need2*(cost2*1LL));
        ll opt1=val+vav;
        ll mini=min(need1,need2);
        ll maxi=max(need1,need2);
        ll opt2=mini*(costBoth*1LL)+((maxi-mini)*1LL)*(need1>need2?cost1:cost2);
        ll opt3=maxi*(costBoth*1LL);
        return min({opt1,opt2,opt3});
    }
};
