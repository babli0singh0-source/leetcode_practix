class Solution {
    int helper(int i,int h,vector<vector<int>>& triangle,vector<vector<int>>&dp,int n){
        if(dp[i][h]!=-1)return dp[i][h];
        if(h==n-1)return triangle[h][i];
        int first=triangle[h][i]+helper(i,h+1,triangle,dp,n);
        int second=triangle[h][i]+helper(i+1,h+1,triangle,dp,n);
        return dp[i][h]=min(first,second);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[n-1][i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                int first=triangle[i][j]+dp[i+1][j];
                int second=triangle[i][j] + dp[i+1][j+1];
                dp[i][j]=min(first,second);
            }
        }
        return dp[0][0];
    }
};
