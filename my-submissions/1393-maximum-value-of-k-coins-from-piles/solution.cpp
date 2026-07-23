class Solution {
    int n;
    int helper(int ind,vector<vector<int>>& piles, int k,vector<vector<int>>&dp){
        //ind is the ith pile we are currently considering and in that pile  am taking a how
        // many i can take from that pile 
        if(ind==n)return 0;
        if(dp[ind][k]!=-1)return dp[ind][k];
        int ans=0;
        int nottake=helper(ind+1,piles,k,dp);
        int take=0;
        for(int i=0;i<piles[ind].size();i++){
            ans+=piles[ind][i];
            if(k-(i+1)<0)break;
            take=max(take,ans+helper(ind+1,piles,k-(i+1),dp));
        }
        return dp[ind][k]=max(nottake,take);
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n=piles.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int rem=0;rem<=k;rem++){
                int ans=0;
                int nottake= dp[ind+1][rem];
                int take=0;
                for(int i=0;i<piles[ind].size();i++){
                    ans+=piles[ind][i];
                    if(rem-(i+1)<0)break;
                    take=max(take,ans+dp[ind+1][rem-(i+1)]);
                }
                dp[ind][rem]=max(nottake,take);
            }
        }
        return dp[0][k];
    }
};
