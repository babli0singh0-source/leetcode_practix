class Solution {
    int helper(int i,int curr,int target,vector<int>& nums,int n,vector<vector<int>>&dp,int &sum){
        if(i==n)return curr==target;
        if(dp[i][curr+sum]!=-1)return dp[i][curr+sum];
        int add=helper(i+1,curr+nums[i],target,nums,n,dp,sum);
        int diff=helper(i+1,curr-nums[i],target,nums,n,dp,sum);
        return dp[i][curr+sum]=add+diff;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(auto &it:nums)sum+=it;
        if (abs(target) > sum)return 0;
        vector<vector<int>>dp(n+1,vector<int>(sum*2+1,0));
        for(int curr=-sum;curr<=sum;curr++)dp[n][curr+sum]=curr==target;
        for(int i=n-1;i>=0;i--){
            for(int curr=-sum;curr<=sum;curr++){
                int add=0;
                int diff=0;
                if(curr+nums[i]<=sum)add=dp[i+1][curr+nums[i]+sum];
                if(curr-nums[i]>=-sum)diff=dp[i+1][curr-nums[i]+sum];
                dp[i][curr+sum]=add+diff;
            }
        }
        return dp[0][sum];
    }
};
