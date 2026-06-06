class Solution {
    long long helper(int i,int currind,vector<int>& nums, string &s,vector<vector<long long>>&dp){
        if(i<0)return 0;
        int token =s[i]-'0';
        long long ans=0;
        if(dp[i][currind]!=-1)return dp[i][currind];
        if(token==0) ans= (currind?nums[i]:0LL)+helper(i-1,0,nums,s,dp);
        else{
            ans=max(ans,nums[i]*1LL+helper(i-1,0,nums,s,dp));
            ans=max(ans,0+(currind?nums[i]:0LL)+helper(i-1,1,nums,s,dp));
        }
        return dp[i][currind]= ans;
    }
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n=nums.size();
        if(n==1)return nums[0]*(s[0]-'0');
        vector<vector<long long>>dp(n,(vector<long long>(2,-1)));
        return helper(n-1,0,nums,s,dp);
    }
};
