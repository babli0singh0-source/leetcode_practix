class Solution {
    // long long helper(int i,vector<int>& nums,vector<long long>&dp){
    //     if(i==0)return dp[0]=nums[0];
    //     if(dp[i]!=-1)return dp[i];
    //     long long sum=LLONG_MIN;
    //     sum=max(sum,nums[i]+helper(i-1,nums,dp));
    //     sum=max(sum,(long long)nums[i]);
    //     return dp[i]=sum;
    // }
public:
    int maxSubArray(vector<int>& nums) {
        //kadane's algo O(N)
        //int n=nums.size();
        //kadane's 
        int curr=0;
        int sum=INT_MIN;
        for(auto &it:nums){
            curr+=it;
            sum=max(curr,sum);
            if(curr<0)curr=0;
        }
        return sum;
        //dp iterative version
        // vector<long long>dp(n+1,LLONG_MIN);
        // dp[0]=nums[0];
        // for(int i=1;i<n;i++){
        //     dp[i]=max(dp[i],nums[i]+dp[i-1]);
        //     dp[i]=max(dp[i],(long long)nums[i]);
        // }
        // long long ans=LLONG_MIN;
        // for(int i=0;i<n;i++){
        //     ans=max(ans,dp[i]);
        // }
        // return ans;
    }
};
