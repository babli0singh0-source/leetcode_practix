class Solution {
public:
//recursion
    // int steps(int n){
    //     if(n==1)return 1;
    //     if(n==0)return 1;
    //     int left =steps(n-1);
    //     int right=steps(n-2);
    //     return left+right;
    // }
    //memoization
    // int steps(int n,vector<int>&dp){
    //     if(n<=1)return 1;
    //     if(dp[n]!=-1)return dp[n];
    //     dp[n]=steps(n-1,dp)+ steps(n-2,dp);
    //     return dp[n];
    // }
    int climbStairs(int n) {
        int prev1=1;
        int prev2=1;
        for(int i=2;i<=n;i++){
            int curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
        // vector<int>dp(n+1,-1);
        // dp[0]=1;
        // dp[1]=1;
        // for(int i=2;i<=n;i++){
        //     dp[i]=dp[i-1]+dp[i-2];
        // }
        // return dp[n];
        //return steps(n,dp);

    }
};
