class Solution {
    int l;
    int n,m;
    bool iscompatible(int c1, int c2, vector<vector<int>>& grid) {
        for (int row = 0; row < m; row++) {
            if (abs(grid[row][c1] - grid[row][c2]) > l)return false;
        }
        return true;
    }
    int helper(int c1,int c2,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(c1==n)return 0;
        if(dp[c1][c2+1]!=-1)return dp[c1][c2+1];
        int nottake=0+helper(c1+1,c2,grid,dp);
        int take=INT_MIN;
        if(c2==-1||iscompatible(c1,c2,grid)){
            take=1+helper(c1+1,c1,grid,dp);
        }
        return dp[c1][c2+1]=max(take,nottake);
    }
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        l=limit;
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return helper(0,-1,grid,dp);
    }
};

