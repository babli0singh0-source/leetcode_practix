class Solution {
    int sumless(vector<int>& nums, int k){
        if(k<0)return 0;
        int n=nums.size();
        int ans=0;
        int sum=0,left=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>k){
                sum-=nums[left];
                left++;
            }
            if(sum<=k)ans=ans+(i-left+1);
        }  
        return ans;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        return sumless(nums,k)-sumless(nums,k-1);
    }
};
