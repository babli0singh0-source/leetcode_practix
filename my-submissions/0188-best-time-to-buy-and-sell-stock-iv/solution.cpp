class Solution {
    int helper(int i,int isbuy,int transaction,int n,vector<int>&profit,vector<vector<vector<int>>>&dp,int k){
        if(transaction>=k)return 0;
        if(i==n)return 0;
        if(dp[i][isbuy][transaction]!=-1)return dp[i][isbuy][transaction];
        if(isbuy){
            int take=-profit[i]+helper(i+1,!isbuy,transaction,n,profit,dp,k);
            int nottake=0+helper(i+1,isbuy,transaction,n,profit,dp,k);
            return dp[i][isbuy][transaction]=max(take,nottake);
        }else{
            int take=profit[i]+helper(i+1,!isbuy,transaction+1,n,profit,dp,k);
            int nottake=0+helper(i+1,isbuy,transaction,n,profit,dp,k);
            return dp[i][isbuy][transaction]=max(take,nottake);
        }
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int i=n-1;i>=0;i--){
            for(int isbuy=0;isbuy<=1;isbuy++){
                for(int transaction=0;transaction<k;transaction++){
                    if(isbuy){
                        int take=-prices[i]+dp[i+1][!isbuy][transaction];
                        int nottake = dp[i+1][isbuy][transaction];
                        dp[i][isbuy][transaction]=max(take,nottake);
                    }else{
                        int take=prices[i]+dp[i+1][!isbuy][transaction+1];
                        int nottake=dp[i+1][isbuy][transaction];
                        dp[i][isbuy][transaction]=max(take,nottake);
                    }
                }
            }
        }
        return dp[0][1][0];
    }
};
