class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<long long>>dp(m,vector<long long>(n,0));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1&&j==n-1){
                    dp[i][j]=1;
                    if(obstacleGrid[i][j]==1)return 0;
                }else if(obstacleGrid[i][j]==1)dp[i][j]=0;
                else{
                    long long down=0,right=0;
                    if(i+1<m) down=dp[i+1][j];
                    if(j+1<n) right=dp[i][j+1];
                    dp[i][j]=down+right;
                }
            }
        }
        return (int)dp[0][0];
    }
};
