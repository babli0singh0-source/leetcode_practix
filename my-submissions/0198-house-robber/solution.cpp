class Solution {
    int helper(int i,int n,vector<int>&nums,vector<int>&dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int take=nums[i]+helper(i+2,n,nums,dp);
        int nottake=helper(i+1,n,nums,dp);
        return dp[i]=max(take,nottake);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+2,0);
        for(int i=n-1;i>=0;i--){
            int take=nums[i]+dp[i+2];
            int nottake=dp[i+1];
            dp[i]=max(take,nottake);
        }
        return dp[0];
    }
};
