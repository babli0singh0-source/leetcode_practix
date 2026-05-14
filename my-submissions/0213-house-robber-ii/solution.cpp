class Solution {
public:
int robber(int prev1,int prev2,vector<int>&nums,int n){
    for(int i=1;i<n;i++){
        int take=nums[i]+prev2;
        int nottake=prev1;
        int curr=max(take,nottake);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        int x=nums.back();
        nums.pop_back();
        int ans1=robber(nums[0],0,nums,n-1);
        nums.push_back(x);
        nums.erase(nums.begin());
        int ans2=robber(nums[0],0,nums,n-1);
        return max(ans1,ans2);
    }
};
