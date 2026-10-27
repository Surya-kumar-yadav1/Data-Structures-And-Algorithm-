//3963. Create Grid With Exactly One Path
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string s="";
        string x="";
        vector<string> ans;
        for(int i=0;i<n;i++){
            s+='#';
            x+='.';
        }
        ans.push_back(x);
        s.pop_back();
        s+='.';
        for(int i=1;i<m;i++){
            ans.push_back(s);
        }
        return ans;
    }
};
