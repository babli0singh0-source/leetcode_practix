class Solution {
public:
    int numDistinct(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        int ans=0;
        vector<vector<double>>dp(n1+1,vector<double>(n2+1,0));
        for(int i=0;i<n1;i++){
            dp[i][0]=1;
        }
        for(int i1=1;i1<=n1;i1++){
            for(int i2=1;i2<=n2;i2++){
                if(s[i1-1]==t[i2-1]) dp[i1][i2]=dp[i1-1][i2]+dp[i1-1][i2-1];
                else dp[i1][i2]=dp[i1-1][i2];
            }
        }
        return static_cast<int>(dp[n1][n2]);
    }
};
