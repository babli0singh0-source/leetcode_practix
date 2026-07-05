class Solution {
    // int helper(vector<vector<int>>&dp,int i,int j){
    //     if(i==mm-1&&j==nn-1)return 1;
    //     if(i>=mm||j>=nn)return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int down=helper(dp,i+1,j);
    //     int right=helper(dp,i,j+1);
    //     return dp[i][j]=down+right;
    // }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1&&j==n-1)dp[i][j]=1;
                else{
                    int down=0,right=0;
                    if(i+1<m) down=dp[i+1][j];
                    if(j+1<n) right=dp[i][j+1];
                    dp[i][j]=down+right;
                }
            }
        }
        return dp[0][0];
    }
};
