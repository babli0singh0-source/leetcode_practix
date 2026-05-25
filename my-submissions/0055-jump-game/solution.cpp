class Solution {
    // bool helper(int i,int n,vector<int>&nums, vector<int>&dp){
    //     if(i==n-1)return true;
    //     if(dp[i]!=-1)return dp[i];
    //     for(int j=1;j<=nums[i];j++){
    //         if(helper(i+j,n,nums,dp))return dp[i]=true;
    //     }
    //     return dp[i]=false;
    // }
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        // vector<int>dp(n+1,-1);
        //return helper(0,n,nums,dp);
        int temp=nums[0];
        for(int i=1;i<n;i++){
            if(temp==0)return false;
            temp--;
            temp=max(temp,nums[i]);
        }
        return true;
        
    }
};
