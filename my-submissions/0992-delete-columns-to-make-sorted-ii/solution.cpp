class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs[0].size(),m=strs.size()-1,ans=0;
        vector<bool>s(m,false);
        for(int i=0;i<n;i++){
            bool check=false;
            for(int j=0;j<m;j++){
                if(!s[j]&&strs[j][i]>strs[j+1][i]){
                    check=true;
                    break;
                }
            }
            if(check){
                ans++;
                continue;
            }
            //if already sorted dont check so fix that for that column 
            for(int j=0;j<m;j++){
                if(!s[j]&&strs[j][i]<strs[j+1][i]){
                    s[j]=true;
                }
            }
        }
        return ans;  
    }
};
