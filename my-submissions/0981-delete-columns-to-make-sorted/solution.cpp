class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs[0].size();
        vector<bool>ans(n,true);
        for(int i=1;i<strs.size();i++){
            for(int j=0;j<n;j++){
                if(strs[i][j]<strs[i-1][j]) ans[j]=false;
            }
        }
        return count(ans.begin(),ans.end(),false);
        
    }
};
