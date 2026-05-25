// class Solution {
//     int helper(int i,int n,vector<int>& nums,vector<int>&dp){
//         if(i==n-1)return 0;
//         if(dp[i]!=-1)return dp[i];
//         int ans=1e8;
//         for(int j=i+1;j<=min(n-1,i+nums[i]);j++){
//             ans=min(ans,1+helper(j,n,nums,dp));
//         }
//         return dp[i]=ans;

//     }
// public:
//     int jump(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>dp(n+1,-1);

//         return helper(0,n,nums,dp);
//     }
// };

class Solution {
public:
    int jump(vector<int>& nums) {
        int temp=0;
        int ans=0;
        int curr=0;
        int n=nums.size();
        if(n==1)return 0;
        for(int i=0;i<n;i++){
            temp=max(temp,i+nums[i]);
            if(curr==i){
                ans++;
                curr=temp;
                if(curr>=n-1)break;
            }
        }
        return ans;
    }
};
