class Solution {
    int n1,n2;
    int helper(int i,int j,string &text1, string &text2, vector<vector<int>>&dp){
        if(i>=n1||j>=n2)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int same=0,diff=0;
        if(text1[i]==text2[j]){
            same=1+helper(i+1,j+1,text1,text2,dp);
        }else{
            diff=max(helper(i+1,j,text1,text2,dp),helper(i,j+1,text1,text2,dp));
        }
        return dp[i][j]=max(same,diff);
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        n1=text1.size();
        n2=text2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                int same=0,diff=0;
                if(text1[i]==text2[j]){
                    same=1+dp[i+1][j+1];
                }else{
                    diff=max(dp[i+1][j],dp[i][j+1]);
                }
                dp[i][j]=max(same,diff);
            }
        }
        return dp[0][0];
    }
};
