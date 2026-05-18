class Solution {
    int helper(int ind,int amount,vector<int>& coins, vector<vector<int>>&dp){
        if(amount==0)return 1;
        else if(ind==0){
            if(amount%coins[0]==0) return 1;
            else return 0;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int nottake= helper(ind-1,amount,coins,dp);
        int take=0;
        if(coins[ind]<=amount)take=helper(ind,amount-coins[ind],coins,dp);
        return dp[ind][amount]=take + nottake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int ind=coins.size();
        vector<vector<int>>dp(ind,vector<int>(amount+1,-1));
        return helper(ind-1,amount,coins,dp);
    }
};
