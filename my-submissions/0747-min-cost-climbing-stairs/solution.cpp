class Solution {
    int helper(int i,vector<int>&cost,vector<int>&dp,int n){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int one=cost[i]+helper(i+1,cost,dp,n);
        int two=cost[i]+helper(i+2,cost,dp,n);
        return dp[i]=min(one,two);

    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+2,0);
        for(int i=n-1;i>=0;i--){
            int one=cost[i]+dp[i+1];
            int two=cost[i]+dp[i+2];
            dp[i]=min(one,two);
        }
        return min(dp[0],dp[1]);
    }
};
