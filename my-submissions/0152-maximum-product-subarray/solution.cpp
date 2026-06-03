class Solution {
    // pair<int,int> prod(vector<int>& nums,int n,int ind,vector<pair<int,int>>&dp){
    //     if(ind>n-1)return {1,1};
    //     if(dp[ind].first!=-1)return dp[ind];
    //     auto val=prod(nums,n,ind+1,dp);
    //     int temp1=max({nums[ind],nums[ind]*val.first,nums[ind]*val.second});
    //     int temp2=min({nums[ind],nums[ind]*val.first,nums[ind]*val.second});
    //     return dp[ind]={temp1,temp2};
    // }
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int currmax=nums[0];
        int currmin=nums[0];
        for(int i=1;i<nums.size();i++){
            int tempmax=max({nums[i],nums[i]*currmax,nums[i]*currmin});
            int tempmin=min({nums[i],nums[i]*currmax,nums[i]*currmin});
            currmax=tempmax;
            currmin=tempmin;
            ans=max(ans,currmax);
        }
        return ans;
    }
};
