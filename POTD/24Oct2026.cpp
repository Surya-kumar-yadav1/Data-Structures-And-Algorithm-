//
//2409. Count Days Spent Together
//
class Solution {
public:
    int toDay(string s,int days[]){
        int m=(s[0]-'0')*10+(s[1]-'0');
        int d=(s[3]-'0')*10+(s[4]-'0');
        int res=d;
        for(int i=0;i<m-1;i++){
            res+=(days[i]);
        }
        return res;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int s1=toDay(arriveAlice,days),s2=toDay(arriveBob,days),e1=toDay(leaveAlice,days),e2=toDay(leaveBob,days);
        int start=max(s1,s2),end=min(e1,e2);
        return start<=end?abs(start-end)+1:0;
    }
};
