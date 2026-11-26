//
//3360. Stone Removal Game
class Solution {
public:
    bool canAliceWin(int n) {
        int cnt=0;
        int store=10;
        while(n>0 && store){
            if(n-store>=0){
                cnt++;
                n=n-store;
                store--;
            }
            else break;
        }
        return cnt%2==1;
    }
};
