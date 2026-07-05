class Solution {
    bool helper(int i,vector<int>& nums,vector<vector<int>>&dp,int curr){
        if(i>=nums.size())return false;
        if(dp[i][curr]!=-1)return dp[i][curr]==1;
        bool take=false;
        if(nums[i]<=curr){
            take=helper(i+1,nums,dp,curr-nums[i]);
        }
        bool nottake=helper(i+1,nums,dp,curr);
        dp[i][curr]=(take||nottake)?1:0;
        return take||nottake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto &it:nums)sum+=it;
        if(sum%2)return false;
        sum=sum/2;
        int n=nums.size();
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
        for(int i=0;i<n;i++) dp[i][0]=true;

        for(int i=n-1;i>=0;i--){
            for(int curr=1;curr<=sum;curr++){
                bool take =false;
                if(nums[i]<=curr)take=dp[i+1][curr-nums[i]];
                bool nottake=dp[i+1][curr];
                dp[i][curr]=take||nottake;
            }
        }
        return dp[0][sum];
    }
};
