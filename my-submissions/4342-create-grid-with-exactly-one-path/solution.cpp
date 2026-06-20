class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;
        string temp="";
        string final="";
        for(int i=1;i<n;i++){
            temp+='#';
            final+='.';
        }
        final+='.';
        for(int i=0;i<m-1;i++){
            string x="."+temp;
            ans.push_back(x);
        }
        ans.push_back(final);
        return ans;   
    }
};
