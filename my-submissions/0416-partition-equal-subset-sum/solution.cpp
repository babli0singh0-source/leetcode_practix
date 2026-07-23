class Solution {
    bool helper(int i,int currsum,int sum,int n,vector<int>& nums,vector<vector<int>>&dp){
        if(currsum==sum)return true;
        if(i==n||currsum>sum)return false;
        if(dp[i][currsum]!=-1)return dp[i][currsum];
        bool take=helper(i+1,currsum+nums[i],sum,n,nums,dp);
        bool nottake=helper(i+1,currsum,sum,n,nums,dp);
        return dp[i][currsum]=take||nottake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int &i:nums){
            sum+=i;
        }
        if(sum%2==1)return false;
        sum=sum/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return helper(0,0,sum,n,nums,dp);
    }
};
