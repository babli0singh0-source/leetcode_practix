class Solution {
    int helper(int i,int isbuy,int transaction,int n,vector<int>&profit,vector<vector<vector<int>>>&dp){
        if(transaction>=2)return 0;
        if(i==n)return 0;
        if(dp[i][isbuy][transaction]!=-1)return dp[i][isbuy][transaction];
        if(isbuy){
            int take=-profit[i]+helper(i+1,!isbuy,transaction,n,profit,dp);
            int nottake=0+helper(i+1,isbuy,transaction,n,profit,dp);
            return dp[i][isbuy][transaction]=max(take,nottake);
        }else{
            int take=profit[i]+helper(i+1,!isbuy,transaction+1,n,profit,dp);
            int nottake=0+helper(i+1,isbuy,transaction,n,profit,dp);
            return dp[i][isbuy][transaction]=max(take,nottake);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return helper(0,1,0,n,prices,dp);
    }
};
