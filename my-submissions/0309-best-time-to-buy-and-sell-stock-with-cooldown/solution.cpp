class Solution {
    int helper(int i,int isbuy,int n,vector<int>&profit,vector<vector<int>>&dp){
        if(i>=n)return 0;
        if(dp[i][isbuy]!=-1)return dp[i][isbuy];
        if(isbuy){
            int take=-profit[i]+helper(i+1,!isbuy,n,profit,dp);
            int nottake=0+helper(i+1,isbuy,n,profit,dp);
            return dp[i][isbuy]=max(take,nottake);
        }else{
            int take=profit[i]+helper(i+2,!isbuy,n,profit,dp);
            int nottake=0+helper(i+1,isbuy,n,profit,dp);
            return dp[i][isbuy]=max(take,nottake);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(0,1,n,prices,dp);
    }
};
