class Solution {
    int helper(int i,int j,int m,int n,vector<vector<int>>&dp,vector<vector<int>>& grid){
        if(i==m-1&&j==n-1)return grid[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int down=INT_MAX;
        int right=INT_MAX;
        if(i+1<m)right=helper(i+1,j,m,n,dp,grid);
        if(j+1<n)down=helper(i,j+1,m,n,dp,grid);
        return dp[i][j]=grid[i][j]+min(right,down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(0,0,m,n,dp,grid);
    }
};

