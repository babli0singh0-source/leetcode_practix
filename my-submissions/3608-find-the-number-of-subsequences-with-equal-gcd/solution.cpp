class Solution {
    //unordered_map<int,vector<int>>mpp;
    const int mod=1e9+7;
    // int find(int gcd,int i){
    //     int ans=0;
    //     for(auto &it:mpp[i]){
    //         if(gcd%it==0)ans=max(ans,it);
    //     }
    //     return ans;
    // }
    int helper(int i,int gcd1,int gcd2,vector<int>& nums,vector<vector<vector<int>>>&dp){
        if(i==nums.size()){
            if(gcd1==gcd2&&gcd1!=0){
                return 1;
            }return 0;
        }
        if(dp[i][gcd1][gcd2]!=-1)return dp[i][gcd1][gcd2];
        int nottake=helper(i+1,gcd1,gcd2,nums,dp);
        int in1=gcd(gcd1,nums[i]);
        int takein1=helper(i+1,in1,gcd2,nums,dp);
        int in2=gcd(gcd2,nums[i]);
        int takein2=helper(i+1,gcd1,in2,nums,dp);
        return dp[i][gcd1][gcd2]=((nottake+takein1)%mod+takein2)%mod;
    }
public:
    int subsequencePairCount(vector<int>& nums) {
        int maxi=0;
        for(int i:nums){
            maxi=max(maxi,i);
        }
        // for(int i=1;;i++){
        //     bool check=false;
        //     for(int it:nums){
        //         if(i<=it)check=true;
        //         if(it%i==0){
        //             mpp[it].push_back(i);
        //         }
        //     }
        //     if(!check){
        //         maxi=i-1;
        //         break;
        //     }
        // }
        int n=nums.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(maxi+1,vector<int>(maxi+1,-1)));
        return helper(0,0,0,nums,dp);
    }
};
