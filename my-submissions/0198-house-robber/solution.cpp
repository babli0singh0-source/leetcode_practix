class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev1=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int take=nums[i]+prev2;
            int nottake= prev1;
            int curr=max(take,nottake);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>dp(n,0);
//         dp[0]=nums[0];
//         for(int i=1;i<n;i++){
//             int take=nums[i];
//             if(i>1)take+=dp[i-2];
//             int nottake= dp[i-1];
//             dp[i]=max(take,nottake);
//         }
//         return dp[n-1];
//     }
// };
