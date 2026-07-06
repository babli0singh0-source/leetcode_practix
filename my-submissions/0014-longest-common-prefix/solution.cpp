class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        if(n==1)return strs[0];
        string ans="";
        int j=0;
        while(j<m){
            for(int i=0;i<n-1;i++){
                if(j>=strs[i].size()||j>=strs[i+1].size()||strs[i][j]!=strs[i+1][j])return ans;
                if(i==n-2){
                    ans+=strs[i][j];
                    j++;
                }
            }
        }
        return ans;
    }
};
