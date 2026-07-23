class Solution {
    int helper(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i==m-1&&j==n-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(i+1<m)ans+=helper(i+1,j,m,n,dp);
        if(j+1<n)ans+=helper(i,j+1,m,n,dp);
        return dp[i][j]=ans;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(0,0,m,n,dp);
    }
};
