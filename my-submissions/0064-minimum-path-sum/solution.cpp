class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1&&j==m-1)dp[n-1][m-1]=grid[n-1][m-1];
                else{
                    int down=INT_MAX,right=INT_MAX;
                    if(i+1<n)down=dp[i+1][j];
                    if(j+1<m)right=dp[i][j+1];
                    dp[i][j]=min(down,right)+grid[i][j];
                    
                }
            }
        }
        return dp[0][0];
    }
};
