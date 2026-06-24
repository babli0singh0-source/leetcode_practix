class Solution {
    int lis(int curr,int prev,vector<int>&nums,vector<vector<int>>&dp){
        if(curr-1==nums.size())return 0;
        if(dp[curr][prev]!=-1)return dp[curr][prev];
        int nottake=0+lis(curr+1,prev,nums,dp);
        int take=INT_MIN;
        if(prev==0||nums[prev-1]<nums[curr-1])take=1+lis(curr+1,curr,nums,dp);
        //cout<<nums[curr]<<endl;
        return dp[curr][prev]=max(take,nottake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int nottake=0+dp[i+1][j+1];
                int take=INT_MIN;
                if(j==-1||nums[j]<nums[i])take=1+dp[i+1][i+1];
                dp[i][j+1]=max(take,nottake);
            }
        }
        return dp[0][0];
    }
};
