class Solution {
public:
    int minInsertions(string s) {
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
        return n-dp[n][n];
    }
};
