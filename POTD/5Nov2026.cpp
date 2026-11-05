//1385. Find the Distance Value Between Two Arrays
//Time Complexity:O(n*m)
//Space Complexity:O(1)
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n=arr1.size(),m=arr2.size(),cnt=0;
        for(int i=0;i<n;i++){
            bool ok=true;
            for(int j=0;j<m;j++){
                int diff=abs(arr1[i]-arr2[j]);
                if(diff<=d) {ok=false;break;}
            }
            if(ok) cnt++;
        }
        return cnt;
    }
};
