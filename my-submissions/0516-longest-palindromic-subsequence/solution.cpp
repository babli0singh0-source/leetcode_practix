class Solution {
    int commonlis(int i1,int i2,string &s1,string &s2,vector<vector<int>>dp){
        if(i1<0||i2<0)return 0;
        if(dp[i1][i2]!=-1)return dp[i1][i2];
        if(s1[i1]==s2[i2])return dp[i1][i2]=1+commonlis(i1-1,i2-1,s1,s2,dp);
        else return dp[i1][i2]=max(commonlis(i1-1,i2,s1,s2,dp),commonlis(i1,i2-1,s1,s2,dp));
    }
public:
    int longestPalindromeSubseq(string s) {
        string s1=s;
        reverse(s.begin(),s.end());
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i1=1;i1<=n;i1++){
            for(int i2=1;i2<=n;i2++){
                if(s1[i1-1]==s[i2-1]) dp[i1][i2]=1+dp[i1-1][i2-1];
                else dp[i1][i2]=max(dp[i1-1][i2],dp[i1][i2-1]);
            }
        }
        return dp[n][n];
    }
};
