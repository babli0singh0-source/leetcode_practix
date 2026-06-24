class Solution {
    int helper(int start,vector<int>& coins,int curramount,vector<vector<int>>&dp){
        if(curramount==0)return 0;
        if(start>=coins.size())return 1e9;
        if(curramount<0)return 1e9;
        if(dp[start][curramount]!=-1)return dp[start][curramount];
        int take=1+helper(start,coins,curramount-coins[start],dp);
        int nottake=0+helper(start+1,coins,curramount,dp);
        return dp[start][curramount]=min(take,nottake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>dp(amount+1,1e9);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(auto &it:coins){
                if(it<=i){
                    dp[i]=min(dp[i],dp[i-it]+1);
                }
            }
        }
        if(dp[amount]>=1e9)return -1;
        return dp[amount];
    }
};
